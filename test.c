#include <stdio.h>
enum animal
{
    DOG,
    CAT,
    MONKEY,
    INVALID
};

enum animal selectAnimal()
{
    int ani;
    do
    {
        printf("0:Dog, 1:Cat, 2:Monkey");
        scanf("%d", &ani);
    } while (ani < DOG || ani > INVALID);
    return ani;
}
int main(void)
{
    printf("%d", selectAnimal());
    return 0;
}