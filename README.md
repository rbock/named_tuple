# named_tuple
A tuple that lets you access members by name, too.

# Example:
```C++
#include <iostream>
#include <named_tuple.h>

int main()
{
  const auto setup = named_tuple::make_named_tuple(
      NAMED_TUPLE_MEMBER(language, std::string("C++")),
      NAMED_TUPLE_MEMBER(standard, 17),
      NAMED_TUPLE_MEMBER(compiler, std::string("clang")),
      NAMED_TUPLE_MEMBER(version, 5.0));

  // normal tuple access
  std::cout << std::get<0>(setup) << std::endl;
  std::cout << std::get<1>(setup) << std::endl;
  std::cout << std::get<2>(setup) << std::endl;
  std::cout << std::get<3>(setup) << std::endl;

  // access by name
  std::cout << setup.language() << std::endl;
  std::cout << setup.standard() << std::endl;
  std::cout << setup.compiler() << std::endl;
  std::cout << setup.version() << std::endl;
}
```

Lovely, right? Let me know if you like it, and let me know if you see ways to improve it, too :-)

# Note:
This is a showcase. Macros are horrible, even simple ones like `NAMED_TUPLE_MEMBER`. I want to be able to do this with reflection and constexpr blocks for real some nice day.

# Requirements:
Tested with clang-6.0 (current trunk). To build the example, I do

```bash
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER=/usr/local/clang-trunk/bin/clang++ \
         -DCMAKE_CXX_FLAGS='-std=c++17 -stdlib=libc++'
```


