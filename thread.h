struct lock_t {
	uint locked;
};

struct arr_lock_t {
	uint locked;
	uint lock_available;	//1 for avail, 0 for waiting
	uint my_place;
};

struct seq_lock_t {
	uint locked;
	uint seq_num;
};

struct mcs_node {
	uint has_lock;		// 1 if holding lock, 0 otherwise
	struct mcs_node *next;
};

struct mcs_lock {
	struct mcs_node *queue;
};

void lock_acquire(struct lock_t *);
void lock_release(struct lock_t *);
void lock_init(struct lock_t *);

void arr_lock_init(struct arr_lock_t *, int *, int);
void arr_lock_acquire(struct arr_lock_t *, int *, int);
void arr_lock_release(struct arr_lock_t *, int *, int);

void seq_lock_init(struct seq_lock_t *);
void seq_lock_acquire(struct seq_lock_t *);
void seq_lock_release(struct seq_lock_t *);
uint seq_lock_read(struct seq_lock_t *t);



void mcs_lock_lock(struct mcs_lock *, struct mcs_node *); 
void mcs_lock_unlock(struct mcs_lock *, struct mcs_node *);


//int thread_create(void *(*start_routine)(void*), void *arg);

