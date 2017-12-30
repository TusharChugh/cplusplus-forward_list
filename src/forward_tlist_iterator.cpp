template <typename T>
T& operator*() {
    return pointee->element;
}

template <typename T>
const forward_tlist_iterator<T>& operator++() {
    assert(pointee != NULL);
    pointee = pointee->next;
    return *this;
}

template <typename T>
bool operator!=(const forward_tlist_iterator<T>& other) const {
    return this->pointee != other.pointee;
}
