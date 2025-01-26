void LinkedList::shiftSmallLarge() {
    if (!head || !head->next) return; // No need to process for empty or single-node lists.

    Node* smallest = head;
    Node* largest = head;
    Node* smallestPrev = nullptr;
    Node* largestPrev = nullptr;
    Node* prev = nullptr;
    Node* current = head;

    // Find smallest and largest nodes
    while (current) {
        if (current->data < smallest->data) {
            smallest = current;
            smallestPrev = prev;
        }
        if (current->data > largest->data) {
            largest = current;
            largestPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    // Move the smallest node to the front
    if (smallest != head) {
        if (smallestPrev) smallestPrev->next = smallest->next; // Detach smallest
        smallest->next = head; // Attach smallest at the front
        head = smallest;
    }

    // Move the largest node to the end
    if (largest->next != nullptr) { // If largest is not already at the end
        if (largestPrev) largestPrev->next = largest->next; // Detach largest
        largest->next = nullptr; // Mark largest as the new tail

        // Attach the largest node to the end
        Node* tail = head;
        while (tail->next) tail = tail->next; // Find the current tail
        tail->next = largest;
    }
}