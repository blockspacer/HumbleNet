#include "../src/humblenet/src/circular_buffer.h"

#include <iostream>

struct Entry {
	int value;

	Entry() : value( 0 ) {}

	explicit Entry(int v) : value( v ) {}
};

int main(int argc, char* argv[])
{
	CircularBuffer<Entry> queue( 5 );

	int e_id = 0;

	std::cout << "Queue State: " << queue.debug() << std::endl;

	std::cout << "Adding 5 entries" << std::endl;

	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));

	std::cout << "Adding more (0): " << queue.push( Entry( ++e_id )) << std::endl;

	std::cout << "Queue State: " << queue.debug() << std::endl;

	Entry e;
	while (queue.pop( e )) {
		std::cout << "Popped: " << e.value << std::endl;
	}

	std::cout << "Queue State: " << queue.debug() << std::endl;

	std::cout << "Adding 3 entries" << std::endl;

	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));

	std::cout << "Queue State: " << queue.debug() << std::endl;

	while (queue.pop( e )) {
		std::cout << "Popped: " << e.value << std::endl;
	}

	std::cout << "Adding 5 entries" << std::endl;

	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));
	queue.push( Entry( ++e_id ));

	std::cout << "Queue State: " << queue.debug() << std::endl;

	queue.pop( e );
	queue.pop( e );

	return 0;
}