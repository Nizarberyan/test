#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100

typedef struct
{
    int code;
    char name[50];
    int quantity;
    float price;
    float price_incl_tax;
} Product;

typedef struct
{
    Product products[MAX_PRODUCTS];
    int count;
} Pharmacy;

typedef struct
{
    int code;
    float price_incl_tax;
    time_t date;
} Purchase;

typedef struct
{
    Purchase purchases[MAX_PRODUCTS];
    int count;
} Sales;

Pharmacy pharmacy = {.count = 0};
Sales sales = {.count = 0};

void add_product()
{
    if (pharmacy.count >= MAX_PRODUCTS)
    {
        printf("Cannot add more products.\n");
        return;
    }

    Product p;
    printf("Enter product code: ");
    scanf("%d", &p.code);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    p.price_incl_tax = p.price * 1.15;
    pharmacy.products[pharmacy.count++] = p;
}

void add_multiple_products()
{
    int n;
    printf("How many products do you want to add? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        add_product();
    }
}

void list_products_by_name()
{
    for (int i = 0; i < pharmacy.count - 1; i++)
    {
        for (int j = i + 1; j < pharmacy.count; j++)
        {
            if (strcmp(pharmacy.products[i].name, pharmacy.products[j].name) > 0)
            {
                Product temp = pharmacy.products[i];
                pharmacy.products[i] = pharmacy.products[j];
                pharmacy.products[j] = temp;
            }
        }
    }
    printf("Listing products in alphabetical order:\n");
    for (int i = 0; i < pharmacy.count; i++)
    {
        printf("Code: %d, Name: %s, Quantity: %d, Price: %.2f, Price Incl. Tax: %.2f\n",
               pharmacy.products[i].code, pharmacy.products[i].name,
               pharmacy.products[i].quantity, pharmacy.products[i].price,
               pharmacy.products[i].price_incl_tax);
    }
}

void list_products_by_price()
{
    for (int i = 0; i < pharmacy.count - 1; i++)
    {
        for (int j = i + 1; j < pharmacy.count; j++)
        {
            if (pharmacy.products[i].price < pharmacy.products[j].price)
            {
                Product temp = pharmacy.products[i];
                pharmacy.products[i] = pharmacy.products[j];
                pharmacy.products[j] = temp;
            }
        }
    }
    printf("Listing products in descending order of price:\n");
    for (int i = 0; i < pharmacy.count; i++)
    {
        printf("Code: %d, Name: %s, Quantity: %d, Price: %.2f, Price Incl. Tax: %.2f\n",
               pharmacy.products[i].code, pharmacy.products[i].name,
               pharmacy.products[i].quantity, pharmacy.products[i].price,
               pharmacy.products[i].price_incl_tax);
    }
}

void buy_product()
{
    int code, quantity;
    printf("Enter product code to buy: ");
    scanf("%d", &code);
    printf("Enter quantity to buy: ");
    scanf("%d", &quantity);

    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].code == code)
        {
            if (pharmacy.products[i].quantity < quantity)
            {
                printf("Insufficient stock!\n");
                return;
            }
            pharmacy.products[i].quantity -= quantity;
            Purchase p = {.code = code, .price_incl_tax = pharmacy.products[i].price_incl_tax * quantity, .date = time(NULL)};
            sales.purchases[sales.count++] = p;
            printf("Purchase successful!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void search_by_code()
{
    int code;
    printf("Enter product code to search: ");
    scanf("%d", &code);

    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].code == code)
        {
            printf("Product found: Code: %d, Name: %s, Quantity: %d, Price: %.2f, Price Incl. Tax: %.2f\n",
                   pharmacy.products[i].code, pharmacy.products[i].name,
                   pharmacy.products[i].quantity, pharmacy.products[i].price,
                   pharmacy.products[i].price_incl_tax);
            return;
        }
    }
    printf("Product not found!\n");
}

void search_by_quantity()
{
    int quantity;
    printf("Enter quantity to search: ");
    scanf("%d", &quantity);

    printf("Products with quantity %d:\n", quantity);
    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].quantity == quantity)
        {
            printf("Code: %d, Name: %s, Quantity: %d, Price: %.2f, Price Incl. Tax: %.2f\n",
                   pharmacy.products[i].code, pharmacy.products[i].name,
                   pharmacy.products[i].quantity, pharmacy.products[i].price,
                   pharmacy.products[i].price_incl_tax);
        }
    }
}

void stock_status()
{
    printf("Products with quantity less than 3:\n");
    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].quantity < 3)
        {
            printf("Code: %d, Name: %s, Quantity: %d, Price: %.2f, Price Incl. Tax: %.2f\n",
                   pharmacy.products[i].code, pharmacy.products[i].name,
                   pharmacy.products[i].quantity, pharmacy.products[i].price,
                   pharmacy.products[i].price_incl_tax);
        }
    }
}

void feed_stock()
{
    int code, quantity;
    printf("Enter product code to feed stock: ");
    scanf("%d", &code);
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].code == code)
        {
            pharmacy.products[i].quantity += quantity;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void remove_product()
{
    int code;
    printf("Enter product code to remove: ");
    scanf("%d", &code);

    for (int i = 0; i < pharmacy.count; i++)
    {
        if (pharmacy.products[i].code == code)
        {
            for (int j = i; j < pharmacy.count - 1; j++)
            {
                pharmacy.products[j] = pharmacy.products[j + 1];
            }
            pharmacy.count--;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void sales_statistics()
{
    if (sales.count == 0)
    {
        printf("No sales made today.\n");
        return;
    }

    float total = 0, max = sales.purchases[0].price_incl_tax, min = sales.purchases[0].price_incl_tax;
    for (int i = 0; i < sales.count; i++)
    {
        total += sales.purchases[i].price_incl_tax;
        if (sales.purchases[i].price_incl_tax > max)
            max = sales.purchases[i].price_incl_tax;
        if (sales.purchases[i].price_incl_tax < min)
            min = sales.purchases[i].price_incl_tax;
    }
    float avg = total / sales.count;

    printf("Sales Statistics:\n");
    printf("Total price of products sold: %.2f\n", total);
    printf("Average price of products sold: %.2f\n", avg);
    printf("Max price of product sold: %.2f\n", max);
    printf("Min price of product sold: %.2f\n", min);
}

void main_menu()
{
    while (1)
    {
        printf("\nPharmacy Management System\n");
        printf("1. Add a new product\n");
        printf("2. Add several new products\n");
        printf("3. List all products by name\n");
        printf("4. List all products by price\n");
        printf("5. Buy a product\n");
        printf("6. Search product by code\n");
        printf("7. Search product by quantity\n");
        printf("8. Show stock status\n");
        printf("9. Feed stock\n");
        printf("10. Remove a product\n");
        printf("11. Show sales statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_product();
            break;
        case 2:
            add_multiple_products();
            break;
        case 3:
            list_products_by_name();
            break;
        case 4:
            list_products_by_price();
            break;
        case 5:
            buy_product();
            break;
        case 6:
            search_by_code();
            break;
        case 7:
            search_by_quantity();
            break;
        case 8:
            stock_status();
            break;
        case 9:
            feed_stock();
            break;
        case 10:
            remove_product();
            break;
        case 11:
            sales_statistics();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}

int main()
{
    main_menu();
    return 0;
}
