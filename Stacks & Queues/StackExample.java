import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        System.out.println("Current size of the stack: " + stack.size());
        System.out.println("Current top element: " + stack.peek());

        stack.pop();
        System.out.println("Stack after deleting top element: " + stack);

        System.out.println("Is stack empty? " + stack.isEmpty());

        stack.clear();
        System.out.println("Stack after removing all elements: " + stack);
        System.out.println("Is stack empty after clearing? " + stack.isEmpty());
    }
}
