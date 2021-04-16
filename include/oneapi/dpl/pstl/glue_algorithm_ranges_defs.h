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

#ifndef _ONEDPL_GLUE_ALGORITHM_RANGES_DEFS_H
#define _ONEDPL_GLUE_ALGORITHM_RANGES_DEFS_H

#include "execution_defs.h"

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
any_of(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

// [alg.all_of]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
all_of(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

// [alg.none_of]

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
none_of(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

// [alg.foreach]

template <typename _ExecutionPolicy, typename _Range, typename _Function>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
for_each(_ExecutionPolicy&& __exec, _Range&& __rng, _Function __f);

// [alg.find]

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find_if(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find_if_not(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
find(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value);

// [alg.find.end]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_end(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_end(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2);

// [alg.find_first_of]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_first_of(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
find_first_of(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2);

// [alg.adjacent_find]

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
adjacent_find(_ExecutionPolicy&& __exec, _Range&& __rng);

template <typename _ExecutionPolicy, typename _Range, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
adjacent_find(_ExecutionPolicy&& __exec, _Range&& __rng, _BinaryPredicate __pred);

// [alg.count]

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
count(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value);

template <typename _ExecutionPolicy, typename _Range, typename _Predicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
count_if(_ExecutionPolicy&& __exec, _Range&& __rng, _Predicate __pred);

// [alg.search]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
search(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __pred);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range1>>
search(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2);

template <typename _ExecutionPolicy, typename _Range, typename _Size, typename _Tp, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
search_n(_ExecutionPolicy&& __exec, _Range&& __rng, _Size __count, const _Tp& __value, _BinaryPredicate __pred);

template <typename _ExecutionPolicy, typename _Range, typename _Size, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
search_n(_ExecutionPolicy&& __exec, _Range&& __rng, _Size __count, const _Tp& __value);

// [alg.copy]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
copy(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __result);

// [alg.transform]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _UnaryOperation>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
transform(_ExecutionPolicy&& __exec, _Range1&& __rng, _Range2&& __result, _UnaryOperation __op);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3, typename _BinaryOperation>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
transform(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __result, _BinaryOperation __op);

// [alg.remove]

template <typename _ExecutionPolicy, typename _Range, typename _UnaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
remove_if(_ExecutionPolicy&& __exec, _Range&& __rng, _UnaryPredicate __pred);

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
remove(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __value);

// [alg.replace]

template <typename _ExecutionPolicy, typename _Range, typename _UnaryPredicate, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
replace_if(_ExecutionPolicy&& __exec, _Range&& __rng, _UnaryPredicate __pred, const _Tp& __new_value);

template <typename _ExecutionPolicy, typename _Range, typename _Tp>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
replace(_ExecutionPolicy&& __exec, _Range&& __rng, const _Tp& __old_value, const _Tp& __new_value);

// [alg.sort]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
sort(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
sort(_ExecutionPolicy&& __exec, _Range&& __rng);

// [stable.sort]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
stable_sort(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
stable_sort(_ExecutionPolicy&& __exec, _Range&& __rng);

// [is.sorted]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
is_sorted_until(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
is_sorted_until(_ExecutionPolicy&& __exec, _Range&& __rng);

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
is_sorted(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
is_sorted(_ExecutionPolicy&& __exec, _Range&& __rng);

// [alg.equal]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _BinaryPredicate>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
equal(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _BinaryPredicate __p);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, bool>
equal(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2);

// [alg.move]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, void>
move(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2);

// [alg.merge]

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range3>>
merge(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __rng3, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range1, typename _Range2, typename _Range3>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy,
                                                      oneapi::dpl::__internal::__difference_t<_Range3>>
merge(_ExecutionPolicy&& __exec, _Range1&& __rng1, _Range2&& __rng2, _Range3&& __rng3);

// [alg.min.max]

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
min_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
min_element(_ExecutionPolicy&& __exec, _Range&& __rng);

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
max_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<_ExecutionPolicy, oneapi::dpl::__internal::__difference_t<_Range>>
max_element(_ExecutionPolicy&& __exec, _Range&& __rng);

template <typename _ExecutionPolicy, typename _Range, typename _Compare>
oneapi::dpl::__internal::__enable_if_execution_policy<
    _ExecutionPolicy,
    ::std::pair<oneapi::dpl::__internal::__difference_t<_Range>, oneapi::dpl::__internal::__difference_t<_Range>>>
minmax_element(_ExecutionPolicy&& __exec, _Range&& __rng, _Compare __comp);

template <typename _ExecutionPolicy, typename _Range>
oneapi::dpl::__internal::__enable_if_execution_policy<
    _ExecutionPolicy,
    ::std::pair<oneapi::dpl::__internal::__difference_t<_Range>, oneapi::dpl::__internal::__difference_t<_Range>>>
minmax_element(_ExecutionPolicy&& __exec, _Range&& __rng);

} // namespace ranges
} // namespace experimental
} // namespace dpl
} // namespace oneapi

#endif /* _ONEDPL_GLUE_ALGORITHM_RANGES_DEFS_H */
