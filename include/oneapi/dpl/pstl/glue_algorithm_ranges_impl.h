// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Copyright (C) Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// This file incorporates work covered by the following copyright and permission
// notice:
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//

#ifndef _ONEDPL_GLUE_ALGORITHM_RANGES_IMPL_H
#define _ONEDPL_GLUE_ALGORITHM_RANGES_IMPL_H

#include "execution_defs.h"
#include "glue_algorithm_defs.h"

#if _ONEDPL_HETERO_BACKEND
#    include "hetero/algorithm_ranges_impl_hetero.h"
#    include "hetero/algorithm_impl_hetero.h" //TODO: for __brick_copy
#endif

namespace oneapi
{
namespace dpl
{
namespace experimental
{
namespace ranges
{

// [alg.any_of]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
any_of(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_any_of(::std::forward<_ExecutionPolicy>(__exec),
                                                               views::all_read(::std::forward<_Range>(__rng)), __pred);
}

// [alg.all_of]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
all_of(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred)
{
    return !any_of(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__not_pred<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, _Predicate>>(
            __pred));
}

// [alg.foreach]

template <typename _ExecutionPolicy, typename _Range, typename _Function>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
for_each(_ExecutionPolicy&& __exec, _Range&& __rng, _Function __f)
{
    oneapi::dpl::__internal::__ranges::__pattern_walk1(::std::forward<_ExecutionPolicy>(__exec),
                                                       views::all(::std::forward<_Range>(__rng)), __f);
}

// [alg.find]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find_if(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_find_if(::std::forward<_ExecutionPolicy>(__exec),
                                                                views::all_read(::std::forward<_Range>(__rng)), __pred);
}

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find_if_not(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred)
{
    return find_if(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__not_pred<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, _Predicate>>(
            __pred));
}

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value)
{
    return find_if(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__equal_value<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, const _Tp>>(
            __value));
}

// [alg.find.end]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_end(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_find_end(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_read(::std::forward<_Range2>(__rng2)), __pred);
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_end(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2)
{
    return find_end(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range1>(__rng1),
                    ::std::forward<_Range2>(__rng2), oneapi::dpl::__internal::__pstl_equal());
}

// [alg.find_first_of]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_first_of(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_find_first_of(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_read(::std::forward<_Range2>(__rng2)), __pred);
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_first_of(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2)
{
    return find_first_of(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range1>(__rng1),
                         ::std::forward<_Range2>(__rng2), oneapi::dpl::__internal::__pstl_equal());
}

// [alg.count]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
count_if(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_count(::std::forward<_ExecutionPolicy>(__exec),
                                                              views::all_read(::std::forward<_Range>(__rng)), __pred);
}

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
count(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value)
{
    return count_if(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__equal_value<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, const _Tp>>(
            __value));
}

// [alg.search]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
search(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_search(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_read(::std::forward<_Range2>(__rng2)), __pred);
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
search(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2)
{
    return search(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range1>(__rng1),
                  ::std::forward<_Range2>(__rng2), oneapi::dpl::__internal::__pstl_equal());
}

template <typename _ExecutionPolicy, typename _Range, typename _Size, typename _Tp, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
search_n(_ExecutionPolicy&& __exec, _Range&& __rng, _Size __count, const _Tp& __value, _BinaryPredicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_search_n(::std::forward<_ExecutionPolicy>(__exec),
                                                                 views::all_read(::std::forward<_Range>(__rng)),
                                                                 __count, __value, __pred);
}

template <typename _ExecutionPolicy, typename _Range, typename _Size, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
search_n(_ExecutionPolicy&& __exec, _Range&& __rng, _Size __count, const _Tp& __value)
{
    return search_n(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng), __count, __value,
                    oneapi::dpl::__internal::__pstl_equal());
}

// [alg.copy]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
copy(_ExecutionPolicy&& __exec, _Range1&& __rng, _Range2&& __result)
{
    oneapi::dpl::__internal::__ranges::__pattern_walk2(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng)),
        views::all_write(::std::forward<_Range2>(__result)), oneapi::dpl::__internal::__brick_copy<_ExecutionPolicy>{});
}

// [alg.transform]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _UnaryOperation>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
transform(_ExecutionPolicy&& __exec, _Range1&& __rng, _Range2&& __result, _UnaryOperation __op)
{
    oneapi::dpl::__internal::__ranges::__pattern_walk2(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng)),
        views::all_write(::std::forward<_Range2>(__result)), [__op](auto x, auto& z) { z = __op(x); });
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3, typename _BinaryOperation>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
transform(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __result, _BinaryOperation __op)
{
    oneapi::dpl::__internal::__ranges::__pattern_walk3(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_read(::std::forward<_Range2>(__rng2)), views::all_write(::std::forward<_Range3>(__result)),
        [__op](auto x, auto y, auto& z) { z = __op(x, y); });
}

// [alg.remove]

template <typename _ExecutionPolicy, typename _Range, typename _UnaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
remove_if(_ExecutionPolicy&& __exec, _Range&& __rng, _UnaryPredicate __pred)
{
    return oneapi::dpl::__internal::__ranges::__pattern_remove_if(::std::forward<_ExecutionPolicy>(__exec),
                                                                  views::all(::std::forward<_Range>(__rng)), __pred);
}

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
remove(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value)
{
    return remove_if(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__equal_value<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, const _Tp>>(
            __value));
}

// [alg.replace]

template <typename _ExecutionPolicy, typename _Range, typename _UnaryPredicate, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
replace_if(_ExecutionPolicy&& __exec, _Range&& __rng, _UnaryPredicate __pred, const _Tp& __new_value)
{
    oneapi::dpl::__internal::__ranges::__pattern_walk1(
        ::std::forward<_ExecutionPolicy>(__exec), views::all(::std::forward<_Range>(__rng)),
        oneapi::dpl::__internal::__replace_functor<
            oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, const _Tp>,
            oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, _UnaryPredicate>>(__new_value, __pred));
}

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
replace(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __old_value, const _Tp& __new_value)
{
    replace_if(
        ::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
        oneapi::dpl::__internal::__equal_value<oneapi::dpl::__internal::__ref_or_copy<_ExecutionPolicy, const _Tp>>(
            __old_value),
        __new_value);
}

// [alg.sort]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
sort(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    oneapi::dpl::__internal::__ranges::__pattern_sort(::std::forward<_ExecutionPolicy>(__exec),
                                                      views::all(::std::forward<_Range>(__rng)), __comp);
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
sort(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    sort(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
         oneapi::dpl::__internal::__pstl_less());
}

// [stable.sort]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
stable_sort(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    sort(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng), __comp);
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
stable_sort(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    sort(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
         oneapi::dpl::__internal::__pstl_less());
}

// [is.sorted]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
is_sorted_until(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    auto __view = views::all_read(::std::forward<_Range>(__rng));
    const auto __res = oneapi::dpl::__internal::__ranges::__pattern_adjacent_find(
        ::std::forward<_ExecutionPolicy>(__exec), __view, oneapi::dpl::__internal::__reorder_pred<_Compare>(__comp),
        oneapi::dpl::__internal::__first_semantic());

    return __res == __view.size() ? __res : __res + 1;
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
is_sorted_until(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    return is_sorted_until(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                           oneapi::dpl::__internal::__pstl_less());
}

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
is_sorted(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    auto __view = views::all_read(::std::forward<_Range>(__rng));
    return oneapi::dpl::__internal::__ranges::__pattern_adjacent_find(
               ::std::forward<_ExecutionPolicy>(__exec), __view,
               oneapi::dpl::__internal::__reorder_pred<_Compare>(__comp),
               oneapi::dpl::__internal::__or_semantic()) == __view.size();
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
is_sorted(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    return is_sorted(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                     oneapi::dpl::__internal::__pstl_less());
}

// [alg.equal]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
equal(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __p)
{
    return oneapi::dpl::__internal::__ranges::__pattern_equal(::std::forward<_ExecutionPolicy>(__exec),
                                                              views::all_read(::std::forward<_Range1>(__rng1)),
                                                              views::all_read(::std::forward<_Range2>(__rng2)), __p);
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
equal(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2)
{
    return equal(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range1>(__rng1),
                 ::std::forward<_Range2>(__rng2), oneapi::dpl::__internal::__pstl_equal());
}

// [alg.move]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
move(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2)
{
    using _DecayedExecutionPolicy = typename ::std::decay<_ExecutionPolicy>::type;

    oneapi::dpl::__internal::__ranges::__pattern_walk2(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_write(::std::forward<_Range2>(__rng2)),
        oneapi::dpl::__internal::__brick_move<_DecayedExecutionPolicy>{});
}

// [alg.merge]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range3>>
merge(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __rng3, _Compare __comp)
{
    return oneapi::dpl::__internal::__ranges::__pattern_merge(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range1>(__rng1)),
        views::all_read(::std::forward<_Range2>(__rng2)), views::all_write(::std::forward<_Range3>(__rng3)), __comp);
}

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range3>>
merge(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __rng3)
{
    return merge(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range1>(__rng1),
                 ::std::forward<_Range2>(__rng2), ::std::forward<_Range3>(__rng3),
                 oneapi::dpl::__internal::__pstl_less());
}

// [alg.min.max]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
min_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    return oneapi::dpl::__internal::__ranges::__pattern_min_element(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range>(__rng)), __comp);
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
min_element(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    return min_element(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                       oneapi::dpl::__internal::__pstl_less());
}

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
max_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    return min_element(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                       oneapi::dpl::__internal::__reorder_pred<_Compare>(__comp));
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
max_element(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    return min_element(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                       oneapi::dpl::__internal::__reorder_pred<oneapi::dpl::__internal::__pstl_less>(
                           oneapi::dpl::__internal::__pstl_less()));
}

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<
    _ExecutionPolicy,
    ::std::pair<oneapi::dpl::__internal::__difference_t<_Range>, oneapi::dpl::__internal::__difference_t<_Range>>>
minmax_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp)
{
    return oneapi::dpl::__internal::__ranges::__pattern_minmax_element(
        ::std::forward<_ExecutionPolicy>(__exec), views::all_read(::std::forward<_Range>(__rng)), __comp);
}

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<
    _ExecutionPolicy,
    ::std::pair<oneapi::dpl::__internal::__difference_t<_Range>, oneapi::dpl::__internal::__difference_t<_Range>>>
minmax_element(_ExecutionPolicy&& __exec, _Range&& __rng)
{
    return minmax_element(::std::forward<_ExecutionPolicy>(__exec), ::std::forward<_Range>(__rng),
                          oneapi::dpl::__internal::__pstl_less());
}

} // namespace ranges
} // namespace experimental
} // namespace dpl
} // namespace oneapi

#endif /* _ONEDPL_GLUE_ALGORITHM_RANGES_IMPL_H */
