def check_equal_heights(heights):
    h_0 = heights[0]
    for h_i in heights[1:]:
        if h_i != h_0:
            return False
    return True


num_blocks = [int(num) for num in input().strip().split()]
num_stacks = len(num_blocks)
stacks = []
for __ in range(num_stacks):
    stack = [int(h) for h in input().strip().split()]
    stacks.append(stack[::-1])

goal = 1
best_height = 0
heights = [0] * num_stacks
positions = [0] * num_stacks
total_blocks = sum(num_blocks)
while sum(positions) < total_blocks:
    for i, stack in enumerate(stacks):
        if positions[i] == num_blocks[i]:
            continue
            
        if heights[i] == goal:
            heights[i] += stack[positions[i]]
            positions[i] += 1
        
        at_end = False
        while heights[i] < goal:
            if positions[i] == num_blocks[i]:
                at_end = True
                break
            heights[i] += stack[positions[i]]
            positions[i] += 1
            
        goal = heights[i]
            
        if at_end:
            continue
            
        if check_equal_heights(heights):
            best_height = heights[i]
            
print(best_height)
