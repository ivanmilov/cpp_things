#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::fstream file("/dev/shmem/test_log", std::ios::out | std::ios::app);

    for (;;)
    {
        static int i{0};
        std::stringstream ss;
        ss << argc << " " << i++ << " sdafihasdlfhalkfhlahjdhg";

        file << ss.str() << std::endl;
    }

    return 0;
}
