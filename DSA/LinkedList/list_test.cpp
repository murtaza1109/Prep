#include <gtest/gtest.h>
#include "List.h"

// Test fixture for List tests
class ListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called before each test
    }

    void TearDown() override {
        // Code here will be called after each test
    }

    // Helper function to create a list with specific values
    List createListWithValues(const std::vector<int>& values) {
        List list;
        for (int val : values) {
            list.push_back(Node(val));
        }
        return list;
    }

    // Helper function to verify list contents
    bool verifyListContents(List& list, const std::vector<int>& expected) {
        Node* current = list.head;
        for (int val : expected) {
            if (!current || current->data != val) {
                return false;
            }
            current = current->next;
        }
        return current == nullptr; // Ensure we've reached the end
    }
};

// ============================================================================
// Basic Operations Tests
// ============================================================================

TEST_F(ListTest, EmptyListCreation) {
    List list;
    EXPECT_EQ(list.head, nullptr);
}

TEST_F(ListTest, PushBackSingleElement) {
    List list;
    Node* node = list.push_back(Node(5));
    
    EXPECT_NE(list.head, nullptr);
    EXPECT_EQ(list.head->data, 5);
    EXPECT_EQ(list.head->next, nullptr);
    EXPECT_EQ(list.tail, node);
}

TEST_F(ListTest, PushBackMultipleElements) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    
    EXPECT_TRUE(verifyListContents(list, {1, 2, 3, 4, 5}));
}

// ============================================================================
// Reverse Tests
// ============================================================================

TEST_F(ListTest, ReverseIterativeEmptyList) {
    List list;
    list.reverse_iterative();
    
    EXPECT_EQ(list.head, nullptr);
}

TEST_F(ListTest, ReverseIterativeSingleElement) {
    List list = createListWithValues({5});
    list.reverse_iterative();
    
    EXPECT_TRUE(verifyListContents(list, {5}));
}

TEST_F(ListTest, ReverseIterativeMultipleElements) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    list.reverse_iterative();
    
    EXPECT_TRUE(verifyListContents(list, {5, 4, 3, 2, 1}));
}

TEST_F(ListTest, ReverseRecursiveEmptyList) {
    List list;
    list.reverse_recursive();
    
    EXPECT_EQ(list.head, nullptr);
}

TEST_F(ListTest, ReverseRecursiveSingleElement) {
    List list = createListWithValues({5});
    list.reverse_recursive();
    
    EXPECT_TRUE(verifyListContents(list, {5}));
}

TEST_F(ListTest, ReverseRecursiveMultipleElements) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    list.reverse_recursive();
    
    EXPECT_TRUE(verifyListContents(list, {5, 4, 3, 2, 1}));
}

TEST_F(ListTest, ReverseStaticMethod) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    List reversed = List::reverse(list);
    
    EXPECT_TRUE(verifyListContents(reversed, {5, 4, 3, 2, 1}));
}

// ============================================================================
// Loop Detection Tests
// ============================================================================

TEST_F(ListTest, NoLoopInEmptyList) {
    List list;
    EXPECT_FALSE(List::doesLoopExist(list));
}

TEST_F(ListTest, NoLoopInNormalList) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    EXPECT_FALSE(List::doesLoopExist(list));
}

TEST_F(ListTest, DetectLoopInLoopedList) {
    List list = List::createLoopedList(5);
    EXPECT_TRUE(List::doesLoopExist(list));
}

TEST_F(ListTest, GetLoopStartingPointReturnsNullForNormalList) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    EXPECT_EQ(List::getLoopStartingPoint(list), nullptr);
}

TEST_F(ListTest, GetLoopStartingPointReturnsNodeForLoopedList) {
    int pos = 5;
    List list = List::createLoopedList(pos);
    Node* loopStart = List::getLoopStartingPoint(list);
    
    EXPECT_NE(loopStart, nullptr);
    EXPECT_EQ(loopStart->data, pos); // Based on createLoopedList implementation
}

TEST_F(ListTest, CalculateLoopLengthReturnsZeroForNormalList) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    EXPECT_EQ(List::calculateLoopLength(list), 0);
}

TEST_F(ListTest, CalculateLoopLengthForLoopedList) {
    int pos = 5;
    List list = List::createLoopedList(pos);
    int loopLength = List::calculateLoopLength(list);
    
    EXPECT_GT(loopLength, 0);
    EXPECT_EQ(loopLength, pos); // Based on createLoopedList creating loop at pos 5
}

// ============================================================================
// List Addition Tests
// ============================================================================

TEST_F(ListTest, AddTwoSingleDigitNumbers) {
    List a = createListWithValues({5});
    List b = createListWithValues({3});
    List sum = List::add(a, b);
    
    EXPECT_TRUE(verifyListContents(sum, {8}));
}

TEST_F(ListTest, AddTwoMultiDigitNumbers) {
    // 123 + 456 = 579
    List a = createListWithValues({1, 2, 3});
    List b = createListWithValues({4, 5, 6});
    List sum = List::add(a, b);
    
    EXPECT_TRUE(verifyListContents(sum, {5, 7, 9}));
}

TEST_F(ListTest, AddWithCarry) {
    // 199 + 1 = 200
    List a = createListWithValues({1, 9, 9});
    List b = createListWithValues({1});
    List sum = List::add(a, b);
    
    EXPECT_TRUE(verifyListContents(sum, {2, 0, 0}));
}

TEST_F(ListTest, AddWithMultipleCarries) {
    // 999 + 999 = 1998
    List a = createListWithValues({9, 9, 9});
    List b = createListWithValues({9, 9, 9});
    List sum = List::add(a, b);
    
    EXPECT_TRUE(verifyListContents(sum, {1, 9, 9, 8}));
}

// ============================================================================
// Y-Bridge Detection Tests
// ============================================================================

TEST_F(ListTest, NoYBridgeInSeparateLists) {
    List a = createListWithValues({1, 2, 3, 4, 5});
    List b = createListWithValues({6, 7, 8, 9, 10});
    
    EXPECT_EQ(List::doesYBridgeExist(a, b), nullptr);
}

TEST_F(ListTest, DetectYBridgeInMergedLists) {
    List a, b;
    List::createYBridgeList(a, b);
    
    Node* mergePoint = List::doesYBridgeExist(a, b);
    EXPECT_NE(mergePoint, nullptr);
}

// ============================================================================
// Remove Node from Back Tests
// ============================================================================

TEST_F(ListTest, RemoveNodeFromBackOfEmptyList) {
    List list;
    list.removeNodeFromBack(1);
    
    EXPECT_EQ(list.head, nullptr);
}

TEST_F(ListTest, RemoveLastNode) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    list.removeNodeFromBack(1);
    
    EXPECT_TRUE(verifyListContents(list, {1, 2, 3, 4}));
}

TEST_F(ListTest, RemoveMiddleNodeFromBack) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    list.removeNodeFromBack(3); // Remove 3rd node from back
    
    EXPECT_TRUE(verifyListContents(list, {1, 2, 4, 5}));
}

TEST_F(ListTest, RemoveFirstNode) {
    List list = createListWithValues({1, 2, 3, 4, 5});
    list.removeNodeFromBack(5);
    
    EXPECT_TRUE(verifyListContents(list, {2, 3, 4, 5}));
}

TEST_F(ListTest, RemoveNodeBeyondListSize) {
    List list = createListWithValues({1, 2, 3});
    list.removeNodeFromBack(10);
    
    // Should not crash and list should remain unchanged
    EXPECT_TRUE(verifyListContents(list, {1, 2, 3}));
}

// ============================================================================
// Edge Cases
// ============================================================================

TEST_F(ListTest, NodeConstructorWithValue) {
    Node node(42);
    EXPECT_EQ(node.data, 42);
    EXPECT_EQ(node.next, nullptr);
}

TEST_F(ListTest, NodeDefaultConstructor) {
    Node node;
    EXPECT_EQ(node.data, 0);
    EXPECT_EQ(node.next, nullptr);
}

TEST_F(ListTest, TailPointerUpdatedCorrectly) {
    List list;
    Node* first = list.push_back(Node(1));
    EXPECT_EQ(list.tail, first);
    
    Node* second = list.push_back(Node(2));
    EXPECT_EQ(list.tail, second);
    
    Node* third = list.push_back(Node(3));
    EXPECT_EQ(list.tail, third);
}

// ============================================================================
// Main function to run all tests
// ============================================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
