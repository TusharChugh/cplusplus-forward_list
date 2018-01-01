#include "forward_tlist/forward_tlist_iterator.h"
#include <assert.h>


template <typename T>
T& tlib::forward_tlist_iterator<T>::operator*() {
    return pointee->element;
}

template <typename T>
const tlib::forward_tlist_iterator<T>& tlib::forward_tlist_iterator<T>::operator++() {
    assert(pointee != nullptr);
    pointee = pointee->next;
    return *this;
}

template <typename T>
bool tlib::forward_tlist_iterator<T>::operator!=(const tlib::forward_tlist_iterator<T>& other) const {
    return this->pointee != other.pointee;
}
