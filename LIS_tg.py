class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def construct_tree(nums, current_index, parent_node):
    if current_index == len(nums):
        return None

    current_value = nums[current_index]
    current_node = Node(current_value)

    for i in range(current_index + 1, len(nums)):
        if nums[i] > current_value:
            child_node = construct_tree(nums, i, current_node)
            if child_node:
                current_node.children.append(child_node)

    if parent_node:
        parent_node.children.append(current_node)

    return current_node

def find_largest_increasing_subsequence(root):
    if not root:
        return []

    current_path = []
    best_path = []

    for child in root.children:
        child_path = find_largest_increasing_subsequence(child)
        if len(child_path) > len(best_path):
            best_path = child_path

    current_path = [root.value] + best_path
    return current_path

def main():
    nums = [4, 1, 13, 7, 0, 2, 8, 11, 3]
    root = construct_tree(nums, 0, None)
    result = find_largest_increasing_subsequence(root)
    
    print("Input Sequence:", nums)
    print("Largest Monotonically Increasing Subsequence:", result)

if __name__ == "__main__":
    main()
