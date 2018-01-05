#include "forward_tlist/forward_tlist.h"

template <typename T, typename allocator>
tlib::forward_tlist<T, allocator>::forward_tlist(const allocator_type &alloc) : tlib::forward_tlist<T, allocator>::__allocator(alloc) {
    tlib::forward_tlist<T, allocator>::init();
};

template <typename T, typename allocator>
void init(){
    tlib::forward_tlist<T, allocator>::__head = tlib::forward_tlist<T, allocator>::create_node(NULL);
    tlib::forward_tlist<T, allocator>::__tail = tlib::forward_tlist<T, allocator>::__head;
    tlib::forward_tlist<T, allocator>::__size(0);
};

template <typename T, typename allocator>
decltype(auto) tlib::forward_tlist<T, allocator>::create_node(const_reference element) {
    auto new_element = __allocator.allocate(1);
    __allocator.construct(new_element, element);
    auto new_node = new forward_tlist_node(element, nullptr);
    return new_node;
}

template <typename T, typename allocator>
void tlib::forward_tlist<T, allocator>::push_front(const_reference element) {
    auto new_node = create_node(element);
    new_node->next = __head;
    __head = new_node;
    __size++;
}
