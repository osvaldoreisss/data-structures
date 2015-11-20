#include <stdlib.h>

#include "entities.h"

ball* entity_createBall(int id, double x, double y, double vx, double vy, double radius)
{
    ball *created = (ball*) malloc(sizeof(ball));

    if (created)
    {
        created->id = id;
        created->x = x;
        created->y = y;
        created->vx = vx;
        created->vy = vy;
        created->radius = radius;

        return created;
    }

    return NULL;
}

void entity_destroyBall(ball *b)
{
    free(b);
}
