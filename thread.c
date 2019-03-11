#include "types.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "thread.h"

void lock_init(struct lock_t *lock) {
	lock->locked = 0;		// Not holding the lock
}

void lock_acquire(struct lock_t *lock) {

	// Disable interrupts to avoid deadlock
	pushcli();

	//Not considering CPU. This might be unnecessary
	//if (*lock == 1) panic("acquire");	
	
	// xchg provides atomic lock acquiring
	//
	while (xchg(&lock->locked, 1) != 0);

}

void lock_release(struct lock_t *lock) {

	// Want to set lock->locked to 0 atomically
	xchg(&lock->locked, 0);
}
