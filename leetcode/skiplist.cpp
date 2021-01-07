static void _add_child_prefix(prefix_t* pfx, prefix_t* chdpfx) {
    if (pfx->header == NULL) pfx->header = (prefix_t*) malloc(sizeof(struct _prefix_t));

    int i, level;
    prefix_t* update[SKIP_MAX_LEVEL + 1];
    prefix_t* skiplist_head = pfx->header;

    for(i = pfx->level; i >= 1; i--) {
        while ( strcmp(skiplist_head->forward[i]->prefix_name, chdpfx->prefix_name) < 0) 
            skiplist_head = skiplist_head->forward[i];
        update[i] = skiplist_head;
    }
    skiplist_head = skiplist_head->forward[i];

    if (chdpfx->prefix_name == skiplist_head->prefix_name) {
        /* pfx->header will be free when pfx header no item */
        return 0;
    }
    else {
        level = rand_level();
        if (level > pfx->level) {
            for (i = pfx->level + 1; i <= level; i++) {
                update[i] = pfx->header;
            }
            pfx->level = level;
        }

        skiplist_head = (prefix_t *) malloc(sizeof(prefix_t*) * (level + 1));
        for (i = 1; i <= level; i++) {
            skiplist_head->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = skiplist_head;
        }
    }
}