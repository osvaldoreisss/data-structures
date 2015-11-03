#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	int interactions, n, max_objects_per_node, max_levels, root_width, root_height, i;
	int object_id, object_x, object_y, object_vx, object_vy, object_radius;

	scanf("%d %d", &interactions, &n);
	scanf("%d %d %d %d", &max_objects_per_node, &max_levels, &root_width, &root_height);


	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d %d", &object_id, &object_x, &object_y, &object_vx, &object_vy, &object_radius);
	}

    return 0;
}
