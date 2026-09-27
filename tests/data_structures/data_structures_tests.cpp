#include <gtest/gtest.h>
#include <cstdlib>
#include <string>

#include "LinkedList.h"
#include "Node.h"
#include "Pair.h"
#include "Queue.h"
#include "priority_queue.h"

TEST(NodeTest, ConstructorsAndMutatorsMaintainItemAndLink) {
    RecordProperty("origin", "white-box");
    Node<int> tail(7);
    Node<int> node(3, &tail);
    EXPECT_EQ(node.getItem(), 3);
    EXPECT_EQ(node.getNext(), &tail);
    node.setItem(9);
    node.setNext(nullptr);
    EXPECT_EQ(node.getItem(), 9);
    EXPECT_EQ(node.getNext(), nullptr);
}

TEST(PairTest, ConstructionCopyAssignmentAndFactory) {
    RecordProperty("origin", "white-box");
    Pair<int, std::string> original(4, "mars");
    Pair<int, std::string> copied(original);
    Pair<int, std::string> assigned;
    assigned = original;
    const auto made = makepair(8, std::string("rover"));
    EXPECT_EQ(copied.first, 4);
    EXPECT_EQ(copied.second, "mars");
    EXPECT_EQ(assigned.first, 4);
    EXPECT_EQ(assigned.second, "mars");
    EXPECT_EQ(made.first, 8);
    EXPECT_EQ(made.second, "rover");
}

// SWE4-FAIL-001
TEST(PriorityNodeTest, ConstructorsAndMutatorsMaintainPriority) {
    RecordProperty("origin", "white-box");
    PriortyNode<int> tail(2, 1.5);
    PriortyNode<int> node(1, 4.0, &tail);
    EXPECT_EQ(node.getItem(), 1);
    EXPECT_DOUBLE_EQ(node.getPriorty(), 4.0);
    EXPECT_EQ(node.getNext(), &tail);
    node.setItem(6);
    node.setPriorty(9.5);
    node.setNext(nullptr);
    EXPECT_EQ(node.getItem(), 6);
    EXPECT_DOUBLE_EQ(node.getPriorty(), 9.5);
    EXPECT_EQ(node.getNext(), nullptr);
}

// SWE4-FAIL-002
TEST(LinkedListTest, StartsEmptyAndSupportsInsertGetRemoveAndClear) {
    RecordProperty("origin", "white-box");
    LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getLength(), 0);
    EXPECT_TRUE(list.insert(1, 10));
    EXPECT_TRUE(list.insert(1, 5));
    EXPECT_TRUE(list.insert(3, 15));
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getLength(), 3);
    EXPECT_EQ(list.getEntry(1), 5);
    EXPECT_EQ(list.getEntry(2), 10);
    EXPECT_EQ(list.getEntry(3), 15);
    EXPECT_TRUE(list.remove(2));
    EXPECT_EQ(list.getEntry(2), 15);
    EXPECT_TRUE(list.remove(1));
    EXPECT_TRUE(list.remove(1));
    EXPECT_TRUE(list.isEmpty());
    list.clear();
    EXPECT_EQ(list.getLength(), 0);
}

TEST(LinkedListTest, RejectsInvalidPositionsWithoutChangingContents) {
    RecordProperty("origin", "white-box");
    LinkedList<int> list;
    EXPECT_FALSE(list.insert(0, 4));
    EXPECT_FALSE(list.insert(2, 4));
    EXPECT_EQ(list.getLength(), 0);
    EXPECT_FALSE(list.remove(0));
    EXPECT_FALSE(list.remove(1));
}

TEST(QueueTest, FifoOperationsAndEmptyFailures) {
    RecordProperty("origin", "white-box");
    Queue<int> queue;
    int value = -1;
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_FALSE(queue.peek(value));
    EXPECT_FALSE(queue.dequeue(value));
    EXPECT_TRUE(queue.enqueue(1));
    EXPECT_TRUE(queue.enqueue(2));
    EXPECT_TRUE(queue.peek(value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(queue.dequeue(value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(queue.dequeue(value));
    EXPECT_EQ(value, 2);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(QueueTest, CopyIsIndependentAndPreservesOrder) {
    RecordProperty("origin", "white-box");
    Queue<int> original;
    original.enqueue(3);
    original.enqueue(4);
    Queue<int> copy(original);
    int value = 0;
    EXPECT_TRUE(original.dequeue(value));
    EXPECT_EQ(value, 3);
    EXPECT_TRUE(copy.dequeue(value));
    EXPECT_EQ(value, 3);
    EXPECT_TRUE(copy.dequeue(value));
    EXPECT_EQ(value, 4);
    EXPECT_TRUE(original.dequeue(value));
    EXPECT_EQ(value, 4);
}

TEST(PriorityQueueTest, DequeuesHighestPriorityFirstAndHandlesEmpty) {
    RecordProperty("origin", "white-box");
    priority_Queue<std::string> queue;
    std::string value;
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_FALSE(queue.peek(value));
    EXPECT_FALSE(queue.dequeue(value));
    EXPECT_TRUE(queue.enqueue("low", 1.0));
    EXPECT_TRUE(queue.enqueue("high", 5.0));
    EXPECT_TRUE(queue.enqueue("middle", 3.0));
    EXPECT_TRUE(queue.peek(value));
    EXPECT_EQ(value, "high");
    EXPECT_TRUE(queue.dequeue(value));
    EXPECT_EQ(value, "high");
    EXPECT_TRUE(queue.dequeue(value));
    EXPECT_EQ(value, "middle");
    EXPECT_TRUE(queue.dequeue(value));
    EXPECT_EQ(value, "low");
    EXPECT_TRUE(queue.isEmpty());
}

TEST(PriorityQueueTest, EqualPrioritiesRemainStableAndCopyIsIndependent) {
    RecordProperty("origin", "white-box");
    priority_Queue<int> original;
    original.enqueue(1, 2.0);
    original.enqueue(2, 2.0);
    priority_Queue<int> copy(original);
    int value = 0;
    EXPECT_TRUE(copy.dequeue(value));
    EXPECT_EQ(value, 1);
    EXPECT_TRUE(copy.dequeue(value));
    EXPECT_EQ(value, 2);
    EXPECT_TRUE(original.peek(value));
    EXPECT_EQ(value, 1);
}

int main(int argc, char** argv) {
    setenv("GTEST_OUTPUT", "json:/app/workspace/clones/data_structures-a42ccdd0cdaa4160a9d04436b1966ee8/test_reports/data_structures/gtest_report.json", 1);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
