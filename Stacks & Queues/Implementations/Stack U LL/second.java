class stack {
    private class stackNode {
      int data;
      stackNode next;
      stackNode(int d) {
        data = d;
        next = null;
      }
    }
    stackNode top = null;
    int size = 0;
    // stack() {
    //   this.top = null;
    //   this.size = 0;
    // }
    public void stackPush(int x) {
      stackNode element = new stackNode(x);
      element.next = top;
      top = element;
      System.out.println("Element pushed");
      size++;
    }
    public int stackPop() {
      if (top == null) return -1;
      int topData = top.data;
      // stackNode temp = top;
      top = top.next;
      // delete temp;
      size--;
      return topData;
    }
    public int stackSize() {
      return size;
    }
    public boolean stackIsEmpty() {
      return top == null;
    }
    public void printStack() {
      stackNode current = top;
      while (current != null) {
        System.out.print(current.data + " ");
        current = current.next;
      }
      System.out.println();
    }
  }
  class second {
    public static void main(String args[]) {
      stack s = new stack();
      s.stackPush(10);
      s.stackPush(20);
      s.stackPop();
      s.printStack();
      System.out.println("Element popped " + s.stackPop());
      System.out.println("Stack size: " + s.stackSize());
      System.out.println("Stack is empty or not: " + s.stackIsEmpty());
  
    }
  }