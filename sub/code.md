# C++ with OpenSSL

* build with  
  `g++ hash.cpp -lcrypto`
* sample: [hash.cpp](hash.cpp) (build with [cppsh](https://github.com/elsamuko/cppsh))

## Code

```C++
#include <openssl/sha.h>

std::string sha256( const std::string& data ) {

    std::string digest( SHA256_DIGEST_LENGTH, '\0' );

    // w/out error handling
    SHA256_CTX sha_ctx = { 0 };
    SHA256_Init( &sha_ctx );
    SHA256_Update( &sha_ctx, data.data(), data.size() );
    SHA256_Final( ( unsigned char* )digest.data(), &sha_ctx );

    return hex( digest );
}
```