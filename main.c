#include <stdint.h>

#define CC_CONCAT2(s1, s2) s1##s2
#define CC_CONCAT(s1, s2) CC_CONCAT2(s1, s2)

#define MEMB(name, structure, num) \
        static char CC_CONCAT(name,_memb_count)[num]; \
        static structure CC_CONCAT(name,_memb_mem)[num]; \
        static struct memb name = {sizeof(structure), num, \
                                          CC_CONCAT(name,_memb_count), \
                                          (void *)CC_CONCAT(name,_memb_mem)}
struct memb {
  unsigned short size;
  unsigned short num;
  char *count;
  void *mem;
};


struct Array{
	uint8_t x[10];
};

int main()
{
	//struct Array data[10];
	MEMB(dataMem, struct Array, 10);
	
}
