/// \copyright Unlicense

#pragma once
#ifndef RRCXX_DSA_LINKED_LIST_INL_
#define RRCXX_DSA_LINKED_LIST_INL_

#include "rrcxx/dsa/linked_list.hxx"

namespace rrcxx::dsa {

template <typename T>
linked_list<T>::linked_list() noexcept :
    sentinel_ {new node}, count_ {0}
{
    sentinel_->prev = sentinel_;
    sentinel_->next = sentinel_;
}

template <typename T>
linked_list<T>::~linked_list() noexcept
{
    for (node *p = sentinel_->next; p != sentinel_; delete p->prev and delete data)
        p = p->next;
    delete sentinel_;
}

}

#endif
