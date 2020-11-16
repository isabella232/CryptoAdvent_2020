#!/usr/bin/env cppsh
// cppsh::LIBS -lcrypto

#include <iostream>
#include <string>

#include <openssl/sha.h>

#define LOG( A ) std::cout << A << std::endl;

std::string hex( const std::string& bytes ) {
    static const char table16[17] = "0123456789abcdef";

    std::string rv( 2 * bytes.size(), '\0' );
    size_t pos = 0;

    for( const uint8_t byte : bytes ) {
        int a = ( byte & 0b11110000 ) >> 4;
        int b = ( byte & 0b00001111 );
        rv[2 * pos + 0] = table16[a];
        rv[2 * pos + 1] = table16[b];
        ++pos;
    }

    return rv;
}

std::string sha256( const std::string& data ) {

    std::string digest( SHA256_DIGEST_LENGTH, '\0' );

    // w/out error handling
    SHA256_CTX sha_ctx = { 0 };
    SHA256_Init( &sha_ctx );
    SHA256_Update( &sha_ctx, data.data(), data.size() );
    SHA256_Final( ( unsigned char* )digest.data(), &sha_ctx );

    return hex( digest );
}

int main( int argc, char* argv[] ) {
    LOG( "echo -n Hase | sha256sum" );
    LOG( sha256( "Hase" ) );
    return 0;
}
