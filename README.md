# lexical cast (C++11)

> 使用C++实现一个boost::lexical_cast功能.

## 思路

C++已经提供了基础的数字转字符串、字符串转数字的接口，例如：`atoi`、`atof`、`atol`、`atoll`、`strtol`、`strtoul`、`strtoll`、`strtoull`、`strtod`、`strtold`、`strtof`、`to_string`。

那如何提供一个统一的接口就是需要我们解决的问题了。

首先，统一的接口应该是这样子的：`dest_type lexcial_cast<dest_type>(src_type)`。

其中，我们需要了解一点，lexical_cast涉及到两种类型，但接口表面上只需要显示的指定一种类型(dest_type)， 那么也就表明会推导类型(src_type)。

```cpp
// dest_type并不对函数模板的特化起作用：返回值的类型是不作为两个模板函数重载的区分的。
template<typename dest_type, typename src_type>
dest_type lexcial_cast<dest_type>(src_type src) {}
```

返回值的类型是不作为两个模板函数重载的区分的. 也就是说，还是需要在函数的形参列表中传递着两个类型(dest_type,src_type)参数，但一个类型作为形参类型，一个作为返回值类型。

这样的函数（暂且称为函数吧）作为统一的接口，然后根据源类型(src_type)以及目标类型(dest_type)进行分别调用不同的接口，进行转化，并返回结果。

考虑到函数并不能返回不同的类型，不存在这种运行期函数多态，那么这些具体实现转化的接口应该也是模板，只通过一个中间转换的接口（就是刚才说`这样的函数`）根据目标类型(dest_type)实例化不同的接口。

最终将其设计为：

```cpp
template <typename DestType, typename SrcType>
struct Converter {
};

// to int
template <typename SrcType>
struct Converter<int, SrcType> {
    static int Convert(const SrcType& src)
    {
        return std::atoi(src);
    }
};

...
...

template <typename DestType, typename SrcType>
typename std::enable_if<!std::is_same<DestType, SrcType>::value, DestType>::type LexicalCast(const SrcType& src)
{
    return LexicalCastDetail::Converter<DestType, SrcType>::Convert(src);
}

template <typename DestType, typename SrcType>
typename std::enable_if<std::is_same<DestType, SrcType>::value, DestType>::type LexicalCast(const SrcType& src)
{
    return src;
}
```

这里还涉及到了，函数模板的自动推导、以及类型匹配相关的知识。

## 功能

+ int <-> string
+ float <-> string
+ double <-> string
+ long double <-> string
+ long <-> string
+ unsigned long <-> string
+ long long <-> string
+ unsigned long long <-> string
+ bool <-> string [true <-> "true", false <-> "false"]



