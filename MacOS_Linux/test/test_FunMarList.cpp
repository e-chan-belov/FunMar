#include "FunMarList.hpp"

#include <gtest.h>

// FunMarListNode

TEST(FunMarListNode, can_create_nodes) {
    ASSERT_NO_THROW(FunMarListNode<int> node);
}

TEST(FunMarListNode, can_init_nodes) {
    ASSERT_NO_THROW(FunMarListNode<int> node(1));
}

TEST(FunMarListNode, can_get_values) {
    const FunMarListNode<int> node(1);
    ASSERT_NO_THROW(node.getValue());
}

TEST(FunMarListNode, can_get_values_correctly) {
    const FunMarListNode<int> node(1);
    EXPECT_EQ(node.getValue(), 1);
}

TEST(FunMarListNode, can_set_values) {
    FunMarListNode<int> node;
    ASSERT_NO_THROW(node.setValue(1));
}

TEST(FunMarListNode, can_set_values_correctly) {
    FunMarListNode<int> node;
    node.setValue(1);
    EXPECT_EQ(node.getValue(), 1);
}

TEST(FunMarListNode, value_references) {
    FunMarListNode<int> node;
    node.getValue() = 1;
    EXPECT_EQ(node.getValue(), 1);
}

TEST(FunMarListNode, can_create_network) {
    FunMarListNode<int> node2(2);
    FunMarListNode<int> node1(1, &node2);
    EXPECT_TRUE(node2.next == nullptr);
    EXPECT_TRUE(node1.next != nullptr);
}

TEST(FunMarListNode, can_create_network_correctly) {
    FunMarListNode<int> node2(2);
    FunMarListNode<int> node1(1, &node2);
    EXPECT_EQ(node1.next->getValue(), 2);
}

TEST(FunMarListNode, can_copy) {
    const FunMarListNode<int> node1(1);
    ASSERT_NO_THROW(FunMarListNode<int> node2(node1));
}

TEST(FunMarListNode, can_copy_correctly) {
    FunMarListNode<int> node1(1);
    FunMarListNode<int> node2(node1);
    node1.setValue(2);
    EXPECT_EQ(node2.getValue(), 1);
}

// FunMarList

TEST(FunMarList, can_create_lists) {
    ASSERT_NO_THROW(FunMarList<int> list);
}

TEST(FunMarList, can_create_lists_with_head_node) {
    FunMarListNode<int>* node = new FunMarListNode<int>(1);
    ASSERT_NO_THROW(FunMarList<int> list(node));
}

TEST(FunMarList, can_size) {
    const FunMarList<int> list;
    ASSERT_NO_THROW(list.size());
}

TEST(FunMarList, can_size_correctly) {
    FunMarListNode<int>* node1 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node2 = new FunMarListNode<int>(2, node1);
    FunMarList<int> list(node2);
    EXPECT_EQ(list.size(), (size_t)2);
    node1->next = new FunMarListNode<int>(1);
    EXPECT_EQ(list.size(), (size_t)3);
}

TEST(FunMarList, can_compare_equal) {
    const FunMarList<int> list1;
    const FunMarList<int> list2;
    ASSERT_NO_THROW(list1 == list2);
}

TEST(FunMarList, can_compare_equal_correctly) {
    FunMarListNode<int>* node11 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node12 = new FunMarListNode<int>(2, node11);
    FunMarList<int> list1(node12);
    
    FunMarListNode<int>* node21 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node22 = new FunMarListNode<int>(2, node21);
    FunMarList<int> list2(node22);
    
    EXPECT_EQ(list1, list2);
    
    node21->setValue(2);
    
    EXPECT_FALSE(list1 == list2);
    
    node21->setValue(1);
    node11->next = new FunMarListNode<int>(1);
    EXPECT_FALSE(list1 == list2);
}

TEST(FunMarList, can_compare_not_equal) {
    const FunMarList<int> list1;
    const FunMarList<int> list2;
    ASSERT_NO_THROW(list1 != list2);
}

TEST(FunMarList, can_compare_not_equal_correctly) {
    FunMarListNode<int>* node11 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node12 = new FunMarListNode<int>(2, node11);
    FunMarList<int> list1(node12);
    
    FunMarListNode<int>* node21 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node22 = new FunMarListNode<int>(2, node21);
    FunMarList<int> list2(node22);
    
    EXPECT_FALSE(list1 != list2);
    
    node21->setValue(2);
    
    EXPECT_NE(list1, list2);
    
    node21->setValue(1);
    node11->next = new FunMarListNode<int>(1);
    EXPECT_NE(list1, list2);
}

TEST(FunMarList, can_copy) {
    const FunMarList<int> list1;
    ASSERT_NO_THROW(FunMarList<int> list2(list1));
}

TEST(FunMarList, can_copy_correctly) {
    FunMarListNode<int>* node1 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node2 = new FunMarListNode<int>(2, node1);
    FunMarList<int> list1(node2);
    
    FunMarList<int> list2(list1);
    EXPECT_EQ(list2, list1);
    node1->setValue(3);
    EXPECT_NE(list2, list1);
}

TEST(FunMarList, can_copy_operator) {
    const FunMarList<int> list1;
    ASSERT_NO_THROW(FunMarList<int> list2 = list1);
}

TEST(FunMarList, can_copy_operator_correctly) {
    FunMarListNode<int>* node1 = new FunMarListNode<int>(1);
    FunMarListNode<int>* node2 = new FunMarListNode<int>(2, node1);
    FunMarList<int> list1(node2);
    
    FunMarList<int> list2 = list1;
    EXPECT_EQ(list2, list1);
    node1->setValue(3);
    EXPECT_NE(list2, list1);
}

// FunMarListGenerator

TEST(FunMarListGenerator, can_create_generator) {
    ASSERT_NO_THROW(FunMarListGenerator<int> generator);
}

TEST(FunMarListGenerator, can_push) {
    FunMarListGenerator<int> generator;
    ASSERT_NO_THROW(generator.push(1));
}

TEST(FunMarListGenerator, can_generate) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    ASSERT_NO_THROW(FunMarList<int> list = generator.generate());
}

TEST(FunMarListGenerator, can_generate_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list1 = generator.generate();
    
    FunMarListNode<int>* node1 = new FunMarListNode<int>(3);
    FunMarListNode<int>* node2 = new FunMarListNode<int>(2, node1);
    FunMarListNode<int>* node3 = new FunMarListNode<int>(1, node2);
    FunMarList<int> list2(node3);
    
    EXPECT_EQ(list1, list2);
}

TEST(FunMarListGenerator, can_generate_multiple_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list1 = generator.generate();
    
    generator.push(4);
    generator.push(5);
    
    FunMarList<int> list3 = generator.generate();
    
    FunMarListNode<int>* node1 = new FunMarListNode<int>(3);
    FunMarListNode<int>* node2 = new FunMarListNode<int>(2, node1);
    FunMarListNode<int>* node3 = new FunMarListNode<int>(1, node2);
    FunMarList<int> list2(node3);
    
    FunMarListNode<int>* node21 = new FunMarListNode<int>(5);
    FunMarListNode<int>* node22 = new FunMarListNode<int>(4, node21);
    FunMarList<int> list4(node22);
    
    EXPECT_EQ(list1, list2);
    EXPECT_EQ(list3, list4);
}

// ObserverIterator

TEST(ObserverIterator, can_create) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(list.begin());
}

TEST(ObserverIterator, can_copy) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(FunMarList<int>::ObserverIterator iter(list.begin()));
}

TEST(ObserverIterator, can_copy_operator) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(FunMarList<int>::ObserverIterator iter = list.begin());
}

TEST(ObserverIterator, can_get_value) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(list.begin().getValue());
}

TEST(ObserverIterator, can_get_value_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    
    EXPECT_EQ(list.begin().getValue(), 1);
}

TEST(ObserverIterator, can_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().next());
}

TEST(ObserverIterator, throws_when_cant_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    const FunMarList<int> list = generator.generate();
    
    FunMarList<int>::ObserverIterator iter = list.begin();
    ASSERT_NO_THROW(iter.next());
    ASSERT_NO_THROW(iter.next());
    ASSERT_NO_THROW(iter.next());
    
    ASSERT_ANY_THROW(iter.next());
}

TEST(ObserverIterator, can_next_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    const FunMarList<int> list = generator.generate();
    
    FunMarList<int>::ObserverIterator iter = list.begin();
    iter.next();
    iter.next();
    
    EXPECT_EQ(iter.getValue(), 3);
}

TEST(ObserverIterator, can_is_at_list) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().isAtList());
}

TEST(ObserverIterator, can_is_at_list_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    const FunMarList<int> list = generator.generate();
    
    FunMarList<int>::ObserverIterator iter = list.begin();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_FALSE(iter.isAtList());
}

TEST(ObserverIterator, can_has_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    const FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().hasNext());
}

TEST(ObserverIterator, can_has_next_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    const FunMarList<int> list = generator.generate();
    
    FunMarList<int>::ObserverIterator iter = list.begin();
    EXPECT_TRUE(iter.hasNext());
    iter.next();
    EXPECT_TRUE(iter.hasNext());
    iter.next();
    EXPECT_FALSE(iter.hasNext());
}

// Iterator

TEST(Iterator, can_create) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(list.begin());
}

TEST(Iterator, can_create_observer_iterator) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(FunMarList<int>::ObserverIterator iter((FunMarList<int>::Iterator)list.begin()));
}

TEST(Iterator, can_copy) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(FunMarList<int>::Iterator iter(list.begin()));
}

TEST(Iterator, can_copy_operator) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(FunMarList<int>::Iterator iter = list.begin());
}

TEST(Iterator, can_get_value) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    ASSERT_NO_THROW(list.begin().getValue());
}

TEST(Iterator, can_get_value_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    
    EXPECT_EQ(list.begin().getValue(), 1);
}

TEST(Iterator, can_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().next());
}

TEST(Iterator, throws_when_cant_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    ASSERT_NO_THROW(iter.next());
    ASSERT_NO_THROW(iter.next());
    ASSERT_NO_THROW(iter.next());
    
    ASSERT_ANY_THROW(iter.next());
}

TEST(Iterator, can_next_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    iter.next();
    iter.next();
    
    EXPECT_EQ(iter.getValue(), 3);
}

TEST(Iterator, can_is_at_list) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().isAtList());
}

TEST(Iterator, can_is_at_list_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_TRUE(iter.isAtList());
    iter.next();
    EXPECT_FALSE(iter.isAtList());
}

TEST(Iterator, can_has_next) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    FunMarList<int> list = generator.generate();
    ASSERT_NO_THROW(list.begin().hasNext());
}

TEST(Iterator, can_has_next_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    EXPECT_TRUE(iter.hasNext());
    iter.next();
    EXPECT_TRUE(iter.hasNext());
    iter.next();
    EXPECT_FALSE(iter.hasNext());
}

TEST(Iterator, can_get_value_reference) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    
    ASSERT_NO_THROW(iter.getValue() = 3);
}

TEST(Iterator, can_get_value_reference_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    
    iter.getValue() = 3;
    
    EXPECT_EQ(iter.getValue(), 3);
}

TEST(Iterator, can_set_value) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    
    ASSERT_NO_THROW(iter.setValue(3));
}

TEST(Iterator, can_set_value_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    iter.setValue(3);
    EXPECT_EQ(iter.getValue(), 3);
}

TEST(Iterator, can_left_merge) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    iter.next();
    iter.next();
    FunMarList<int>::Iterator iterLeft = list.begin();
    iterLeft.next();
    
    ASSERT_NO_THROW(iter.leftMerge(iterLeft, 5));
}

TEST(Iterator, can_left_merge_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    size_t size = list.size();
    
    FunMarList<int>::Iterator iter = list.begin();
    iter.next();
    iter.next();
    FunMarList<int>::Iterator iterLeft = list.begin();
    iterLeft.next();
    
    iter.leftMerge(iterLeft, 5);
    
    EXPECT_EQ(iter.getValue(), 5);
    EXPECT_EQ(list.size(), size - 1);
    
    FunMarList<int>::Iterator check = list.begin();
    
    EXPECT_EQ(check.getValue(), 1);
    ASSERT_NO_THROW(check.next());
    EXPECT_EQ(check.getValue(), 5);
}

TEST(Iterator, can_right_merge) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    
    FunMarList<int>::Iterator iter = list.begin();
    
    ASSERT_NO_THROW(iter.rightMerge(3));
}

TEST(Iterator, can_right_merge_correctly) {
    FunMarListGenerator<int> generator;
    generator.push(1);
    generator.push(2);
    generator.push(3);
    
    FunMarList<int> list = generator.generate();
    size_t size = list.size();
    
    FunMarList<int>::Iterator iter = list.begin();
    
    iter.rightMerge(3);
    
    EXPECT_EQ(iter.getValue(), 3);
    EXPECT_EQ(list.size(), size - 1);
    
    FunMarList<int>::Iterator check = list.begin();
    
    EXPECT_EQ(check.getValue(), 3);
    ASSERT_NO_THROW(check.next());
    EXPECT_EQ(check.getValue(), 3);
}
