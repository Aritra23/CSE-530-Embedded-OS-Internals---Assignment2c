# Usage of kmem_cache_alloc() for adding storage capacity in driver.
There are two applications of the driver module where the write application writes the total content size into the buffer. The read application on the other hand reads the content of the buffer and then frees the buffer on its one invocation.
