#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

int main(int argc, char* argv[])
{
	size_t bucket_size;
	size_t nr_elements;
	hkey_t* keys = NULL;
	hkey_t key;
	hashq_t* p_hashq = NULL;
	status_t status;
	size_t i;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s bucket_size nr_elements\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	bucket_size = atoll(argv[1]);
	nr_elements = atoll(argv[2]);

	keys = (hkey_t*)xmalloc(nr_elements * sizeof(hkey_t));
	for(i = 0; i < nr_elements; ++i)
		keys[i] = rand();

	p_hashq = create_hashq(bucket_size);
	for(i = 0; i < nr_elements; ++i)
	{
		status = add_key(p_hashq, keys[i]);
		assert(status == SUCCESS);
	}

	hash_stat(p_hashq);

	puts("Search key test: SUCCESS CASES");
	for(i = 0; i < 5; ++i)
	{
		key = keys[rand() % nr_elements];
		printf("Searching for key:%zu\n", key);
		status = search_key(p_hashq, key);
		assert(status == TRUE);
		printf("Key:%zu found\n", key);
	}

	puts("Search key test: RANDOM CASES");
	for(i = 0; i < 5; ++i)
	{
		key = rand();
		printf("Searching for key:%zu\n", key);
		status = search_key(p_hashq, key);
		if(status == TRUE)
			printf("Key:%zu found\n", key);
		else
			printf("Key:%zu not found\n", key);
	}

	key = keys[rand() % nr_elements];
	printf("Key to be removed:%zu\n", key);
	status = remove_key(p_hashq, key);
	assert(status == SUCCESS);
	assert(search_key(p_hashq, key) == FALSE);

	status = destroy_hashq(&p_hashq);
	assert(status == SUCCESS && p_hashq == NULL);

	free(keys);
	keys = NULL;

	return (EXIT_SUCCESS);
}
