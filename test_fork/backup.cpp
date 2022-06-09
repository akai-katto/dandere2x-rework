//// waifu2x implemented with ncnn library
//
//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <clocale>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
//
//#if _WIN32
//// image decoder and encoder with wic
//#include "wic_image.h"
//#else // _WIN32
//// image decoder and encoder with stb
//#define STB_IMAGE_IMPLEMENTATION
////#define STBI_NO_PSD
////#define STBI_NO_TGA
////#define STBI_NO_GIF
////#define STBI_NO_HDR
////#define STBI_NO_PIC
////#define STBI_NO_STDIO
//
//#include "stb_image.h"
//
//#define STB_IMAGE_WRITE_IMPLEMENTATION
//
//#include "stb_image_write.h"
//
//#endif // _WIN32
//
//#include "webp_image.h"
//
//#if _WIN32
//#include <wchar.h>
//static wchar_t* optarg = NULL;
//static int optind = 1;
//static wchar_t getopt(int argc, wchar_t* const argv[], const wchar_t* optstring)
//{
//    if (optind >= argc || argv[optind][0] != L'-')
//        return -1;
//
//    wchar_t opt = argv[optind][1];
//    const wchar_t* p = wcschr(optstring, opt);
//    if (p == NULL)
//        return L'?';
//
//    optarg = NULL;
//
//    if (p[1] == L':')
//    {
//        optind++;
//        if (optind >= argc)
//            return L'?';
//
//        optarg = argv[optind];
//    }
//
//    optind++;
//
//    return opt;
//}
//
//static std::vector<int> parse_optarg_int_array(const wchar_t* optarg)
//{
//    std::vector<int> array;
//    array.push_back(_wtoi(optarg));
//
//    const wchar_t* p = wcschr(optarg, L',');
//    while (p)
//    {
//        p++;
//        array.push_back(_wtoi(p));
//        p = wcschr(p, L',');
//    }
//
//    return array;
//}
//#else // _WIN32
//
//#include <unistd.h> // getopt()
//#include <iostream>
//#include <netinet/in.h>
//#include <thread>
//
//using namespace std;
//using namespace std::chrono;
//
//class Writer {
//public:
//    static unsigned char *byte_array;
//    static unsigned int offset;
//    static void dummy_write(void *context, void *data, int len) {
//        //if (len > 1024) len = 1024;
//        memcpy(Writer::byte_array + offset, data, len);
//
////        cout << "called" << endl;
////        for (int i = 0; i < len; i++) {
////            cout << (int) Writer::byte_array[i] << endl;
////        }
//        Writer::offset += len;
//    }
//};
//unsigned char *Writer::byte_array = new unsigned char[500000000];
//unsigned int Writer::offset = 0;
//
////Client side
//void send_image(unsigned int port, unsigned char *image, unsigned int image_size) {
//
//    /// Hyper Paramaters //
//    const int MSG_SIZE = 1024;
//
//    /// Book Keeping ///
//    unsigned int total_chunks = (image_size / MSG_SIZE) + 1;
//
//    /// SETUP SERVER BLOCK ///
//
//    //create a message buffer
//    char msg[MSG_SIZE];
//    //setup a socket and connection tools
//    struct hostent *host = gethostbyname("localhost");
//    sockaddr_in sendSockAddr;
//    bzero((char *) &sendSockAddr, sizeof(sendSockAddr));
//    sendSockAddr.sin_family = AF_INET;
//    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *) *host->h_addr_list));
//    sendSockAddr.sin_port = htons(port);
//
//    int clientSd = socket(AF_INET, SOCK_STREAM, 0);
//    int option = 1;
//    setsockopt(clientSd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
//
//    int status;
//    //try to connect...
//    do {
//        status = connect(clientSd, (sockaddr *) &sendSockAddr, sizeof(sendSockAddr));
//        if (status < 0)
//            std::this_thread::sleep_for(std::chrono::milliseconds(50));
//
//    } while (status < 0);
//
//    /// DONE SETTING UP! ///
//
//    cout << "Connected to the server!" << endl;
//    for (int chunk_iter = 0; chunk_iter < total_chunks; chunk_iter++) {
//        memset(&msg, 0, sizeof(msg)); //clear the buffer
//
//        for (int msg_iter = 0; msg_iter < MSG_SIZE; msg_iter++){
//            int current_pos = (chunk_iter * MSG_SIZE) + msg_iter;
//
//            if (current_pos < image_size)
//                msg[msg_iter] = image[current_pos];
//            else
//                msg[msg_iter] = '\00';
//
//
//        }
//        send(clientSd, (char *) &msg, MSG_SIZE, 0);
//        recv(clientSd, (char *) &msg, MSG_SIZE, 0);
//    }
//    cout << "finished" << endl;
//    send(clientSd, nullptr, strlen(msg), 0);
//    close(clientSd);
//}
//
//
//void get_image_from_socket(unsigned int port, unsigned char **data, int &w, int &h, int &n){
//
//    // Hyper Paramters
//    const int MSG_SIZE = 16384;  // Max Packet Size
//    const int FILE_LIMIT = 20000000;  // 20mb
//
//    // Socket Setup
//    //setup a socket and connection tools
//    sockaddr_in servAddr;
//    bzero((char *) &servAddr, sizeof(servAddr));
//    servAddr.sin_family = AF_INET;
//    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//    servAddr.sin_port = htons(port);
//
//    //open stream oriented socket with internet address
//    //also keep track of the socket descriptor
//    int serverSd = socket(AF_INET, SOCK_STREAM, 0);
//
//    // Register socket as re-usable so we're not by TIME_WAIT constraints.
//    int option = 1;
//    setsockopt(serverSd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
//
//    if (serverSd < 0) {
//        cerr << "Error establishing the server socket" << endl;
//        exit(0);
//    }
//    //bind the socket to its local address
//    int bindStatus = bind(serverSd, (struct sockaddr *) &servAddr,
//                          sizeof(servAddr));
//    if (bindStatus < 0) {
//        cerr << "Error binding socket to local address" << endl;
//        exit(0);
//    }
//    cout << "Waiting for a client to connect..." << endl;
//
//    listen(serverSd, 5); // Listen for up to 5 requests at a time
//    // Receive a request from client using accept. We need a new address to connect with the client
//    sockaddr_in newSockAddr;
//    socklen_t newSockAddrSize = sizeof(newSockAddr);
//
//
//    //accept, create a new socket descriptor to handle the new connection with client
//    int newSd = accept(serverSd, (sockaddr *) &newSockAddr, &newSockAddrSize);
//    if (newSd < 0) {
//        cerr << "Error accepting request from client!" << endl;
//        exit(1);
//    }
//    //    Socket Setup End   //
//    //-----===---------------//
//    // Begin Listening Stage //
//
//
//    char received_message[MSG_SIZE]; // buffer to send and receive messages with
//    unsigned char *buffered_in_file = new unsigned char[FILE_LIMIT]; // A char buffer to buf
//    long long location = 0;  // A pointer of sorts mapping the last pointed to location.
//
//    // Infinite loop until "exit" message sent to the port.
//    while(true) {
//        // Clear the buffer
//        memset(&received_message, 0, sizeof(received_message));
//        // Receive next message
//        recv(newSd, (char *) &received_message, sizeof(received_message), 0);
//
//        // If the message is "exit", then it's time to break the packet receiving loop.
//        if (!strcmp(received_message, "exit")){
//            break;
//        }
//
//        // Write the received message into the buffer.
//        for (char i: received_message) {
//            buffered_in_file[location] = i;
//            location += 1;
//        }
//
//        // Send a friendly "ack" to our python friend.
//        string data = "ack";
//        memset(&received_message, 0, sizeof(received_message)); // clear the buffer
//        strcpy(received_message, data.c_str());
//        send(newSd, (char *) &received_message, 64, 0);
//
//    };
//
//    //we need to close the socket descriptors after we're all done
//    close(newSd);
//    close(serverSd);
//    cout << "port: " << port << " connection closed..." << endl;
//
//    // Finally, load the
//    *data = stbi_load_from_memory(
//            (unsigned char *) buffered_in_file, location, &w, &h, &n, 3);
//}
//
//#endif // _WIN32
//
//// ncnn
//#include "cpu.h"
//#include "gpu.h"
//#include "platform.h"
//
//#include "waifu2x.h"
//
//#include "filesystem_utils.h"
//
//#include "boost/asio.hpp"
//using boost::asio::ip::tcp;
//
//int main(int argc, char **argv)
//{
//    tcp::socket socket(void);
//
//    path_t inputpath;
//    path_t outputpath;
//    int noise = 0;
//    int scale = 2;
//    std::vector<int> tilesize;
//    path_t model = PATHSTR("models-cunet");
//    std::vector<int> gpuid;
//    int jobs_load = 1;
//    std::vector<int> jobs_proc;
//    int jobs_save = 2;
//    int verbose = 0;
//    int tta_mode = 0;
//    path_t format = PATHSTR("png");
//
//
//    Waifu2x* waifu2x = new Waifu2x(0, tta_mode, 8);
//    waifu2x->load(sanitize_filepath("/home/tyler/CLionProjects/test_clion/cmake-build-debug/models-cunet/noise0_scale2.0x_model.param"),
//                  sanitize_filepath("/home/tyler/CLionProjects/test_clion/cmake-build-debug/models-cunet/noise0_scale2.0x_model.bin"));
//
//    waifu2x->noise = noise;
//    waifu2x->scale = (scale >= 2) ? 2 : scale;
//    waifu2x->tilesize = 800;
//    waifu2x->prepadding = 18;
//
//    int w,h, c;
//    int n = 3;
//
//    string some_string = "/home/tyler/Downloads/yn_moving/output/output28.png";
//    unsigned char *some_array;// = stbi_load(some_string.c_str(), &w, &h, &c, n);
//
//    get_image_from_socket(7003, &some_array, w,h, n);
//    ncnn::Mat inimage = ncnn::Mat(1920, 1080, (void *) some_array, (size_t) n, n);
//    ncnn::Mat outimage = ncnn::Mat(1920 * 2, 1080 * 2, (size_t) n, (int) n);
//    auto start = std::chrono::high_resolution_clock::now();
//    waifu2x->process(inimage, outimage);
//
//    cout << "waiting on receive" << endl;
//
//    stbi_write_bmp_to_func(Writer::dummy_write, 0, outimage.w, outimage.h, n, outimage.data);
//    send_image(7005, Writer::byte_array, Writer::offset);
//
//
//
//    return 0;
//}
