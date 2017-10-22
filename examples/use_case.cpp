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

