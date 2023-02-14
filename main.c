#include <stdio.h>
#include <stdlib.h>

struct item {
  int id;
  char name[30];
  float price;
};

struct order {
  int item_id;
  int quantity;
};

struct item menu[] = {
  {1, "Burger", 50.00},
  {2, "Pizza", 80.00},
  {3, "Fries", 25.00},
  {4, "Salad", 35.00},
  {5, "Soda", 20.00},
};

float calculate_total(struct order *orders, int num_orders) {
  float total = 0.0;
  int i;
  for (i = 0; i < num_orders; i++) {
    struct item item = menu[orders[i].item_id - 1];
    total += orders[i].quantity * item.price;
  }
  return total;
}

void print_menu() {
  printf("Food menu:\n");
  int i;
  for (i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
    struct item item = menu[i];
    printf("%d. %s (%0.2f)\n", item.id, item.name, item.price);
  }
}

void take_order(struct order *orders, int *num_orders) {
  int item_id, quantity;
  printf("Enter item ID: ");
  scanf("%d", &item_id);
  printf("Enter quantity: ");
  scanf("%d", &quantity);
  orders[*num_orders].item_id = item_id;
  orders[*num_orders].quantity = quantity;

  *num_orders += 1;
}

int main() {
  struct order orders[100];
  int num_orders = 0;

  while (1) {
    printf("1. Display menu\n");
    printf("2. Take order\n");
    printf("3. Display bill\n");
    printf("4. Exit\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      print_menu();
    } else if (choice == 2) {
      take_order(orders, &num_orders);
    } else if (choice == 3) {
      float total = calculate_total(orders, num_orders);
      printf("Total bill: $%0.2f\n", total);
    } else if (choice == 4) {
      break;
    } else {
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}
