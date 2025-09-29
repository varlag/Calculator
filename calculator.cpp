#include <iostream> 
#include <stack> 

using namespace std; 

struct Leksema {

    char type; 
    double value; 

};

int getRang(char Ch) {

    if (Ch == '+' || Ch == '-') {
        return 1;
    } else if (Ch == '*' || Ch == '/') {
        return 2;
    } else {
        return 0;
    }
    
}

bool Maths(stack <Leksema> & Stack_for_numbers, stack <Leksema> & Stack_for_operations, Leksema& item) {

    double a, b, c;
    a = Stack_for_numbers.top().value;
    Stack_for_numbers.pop();

    switch(Stack_for_operations.top().type) {

        case '+':

        b = Stack_for_numbers.top().value;
        Stack_for_numbers.pop();

        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_for_numbers.push(item);
        Stack_for_operations.pop();
        break;
       
        case '-':

        b = Stack_for_numbers.top().value;
        Stack_for_numbers.pop();

        c = a - b;
        item.type = '0';
        item.value = c;
        Stack_for_numbers.push(item);
        Stack_for_operations.pop();
        break;
       
        case '*':

        b = Stack_for_numbers.top().value;
        Stack_for_numbers.pop();

        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_for_numbers.push(item);
        Stack_for_operations.pop();
        break;

        case '/':

        b = Stack_for_numbers.top().value;
        Stack_for_numbers.pop();
        if (a != 0) {
            c = b / a;
            item.type = '0';
            item.value = c;
            Stack_for_numbers.push(item);
            Stack_for_operations.pop();
            break; 
        } else {
            cout << "you are really dalbaeb..." << '\n';
            return false;
        }

    }
    return true;
}

int main() {
    double value;
    char Ch; 
    Leksema item; 

    stack <Leksema> Stack_for_numbers; 
    stack <Leksema> Stack_for_operations; 
    

    while (true) {
        Ch = cin.peek();

        if (Ch == '\n') {
            break;
        }

        if (Ch >= '0' && Ch <= '9') {
                cin >> value;
                item.type = '0';
                item.value = value;
                Stack_for_numbers.push(item);
                continue;
        }

        if (Ch == '+' || Ch == '-' || Ch == '*' || Ch == '/') {

            if (Stack_for_operations.size() == 0) {
                item.type = Ch;
                item.value = 0;
                Stack_for_operations.push(item);
                cin.ignore();
                continue;
            } 

            if (Stack_for_operations.size() != 0 && getRang(Ch) > getRang(Stack_for_operations.top().type)) { 
                item.type = Ch;
                item.value = 0;
                Stack_for_operations.push(item); 
                cin.ignore();
                continue;
            }

            if (Stack_for_operations.size() != 0 && getRang(Ch) <= getRang(Stack_for_operations.top().type)) {
                if (Maths(Stack_for_numbers, Stack_for_operations, item) == false) { 
                    return 0;
                }
                continue;
            }
        }
    }
    while (Stack_for_operations.size() != 0) { 
        if (Maths(Stack_for_numbers, Stack_for_operations, item) == false) { 
            return 0;
        } else {
            continue; 
        }
    }
    cout << Stack_for_numbers.top().value << endl; 
    return 0;
    
}