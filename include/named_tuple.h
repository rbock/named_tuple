#pragma once

#include <tuple>
#include <utility>

#define NAMED_TUPLE_MEMBER(name, expr)               \
  std::pair                                          \
  {                                                  \
    [](const auto& base, const auto& index) {        \
      using base_t = std::decay_t<decltype(base)>;   \
      using index_t = std::decay_t<decltype(index)>; \
      struct accessor : public base_t                \
      {                                              \
        using base_t::base_t;                        \
        decltype(auto) name()                        \
        {                                            \
          return std::get<index_t::value>(*this);    \
        }                                            \
        decltype(auto) name() const                  \
        {                                            \
          return std::get<index_t::value>(*this);    \
        }                                            \
      };                                             \
      return accessor{};                             \
    },                                               \
        expr                                         \
  }

namespace named_tuple::detail
{
  template <typename Base, size_t index, typename... Names>
  struct named_tuple;

  template <typename Base, size_t ignored>
  struct named_tuple<Base, ignored> : public Base
  {
    using Base::Base;
  };

  template <typename Base, size_t index, typename Name, typename... Rest>
  struct named_tuple<Base, index, Name, Rest...>
      : decltype(std::declval<Name>()(
            std::declval<named_tuple<Base, index + 1, Rest...>>(),
            std::integral_constant<size_t, index>{}))
  {
    using _base = decltype(std::declval<Name>()(
        std::declval<named_tuple<Base, index + 1, Rest...>>(),
        std::integral_constant<size_t, index>{}));
    using _base::_base;
  };
}

namespace named_tuple
{
  template <typename... Names, typename... Types>
  auto make_named_tuple(std::pair<Names, Types>... pairs)
  {
    using X = detail::named_tuple<std::tuple<Types...>, 0, Names...>;
    return X{std::move(pairs.second)...};
  }
}
