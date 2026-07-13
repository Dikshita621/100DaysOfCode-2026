def reverse_string_with_stack(s: str) -> str:
    # In Python, a standard list serves perfectly as a stack
    stack = []
    
    # Step 1: Push all characters of the string onto the stack
    for char in s:
        stack.append(char)
        
    reversed_s = ""
    
    # Step 2: Pop characters from the stack until it's empty
    while len(stack) > 0:
        reversed_s += stack.pop()
        
    return reversed_s

# Example Usage
input_str = "hello"
output_str = reverse_string_with_stack(input_str)

print(f"Input:  {input_str}")
print(f"Output: {output_str}")
