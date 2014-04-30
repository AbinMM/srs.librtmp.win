/*
The MIT License (MIT)

Copyright (c) 2013-2014 winlin

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef SRS_CORE_HPP
#define SRS_CORE_HPP

/*
#include <srs_core.hpp>
*/

// current release version
#define VERSION_MAJOR "0"
#define VERSION_MINOR "9"
#define VERSION_REVISION "78"
#define RTMP_SIG_SRS_VERSION VERSION_MAJOR"."VERSION_MINOR"."VERSION_REVISION
// server info.
#define RTMP_SIG_SRS_KEY "srs"
#define RTMP_SIG_SRS_ROLE "origin server"
#define RTMP_SIG_SRS_NAME RTMP_SIG_SRS_KEY"(simple rtmp server)"
#define RTMP_SIG_SRS_URL "https://"RTMP_SIG_SRS_URL_SHORT
#define RTMP_SIG_SRS_URL_SHORT "github.com/winlinvip/simple-rtmp-server"
#define RTMP_SIG_SRS_WEB "http://blog.csdn.net/win_lin"
#define RTMP_SIG_SRS_EMAIL "winlin@vip.126.com"
#define RTMP_SIG_SRS_LICENSE "The MIT License (MIT)"
#define RTMP_SIG_SRS_COPYRIGHT "Copyright (c) 2013-2014 winlin"
#define RTMP_SIG_SRS_PRIMARY_AUTHROS "winlin,wenjie.zhao"
#define RTMP_SIG_SRS_CONTRIBUTORS_URL "https://github.com/winlinvip/simple-rtmp-server/blob/master/AUTHORS.txt"

/**
* the core provides the common defined macros, utilities,
* user must include the srs_core.hpp before any header, or maybe 
* build failed.
*/

// for 32bit os, 2G big file limit for unistd io, 
// ie. read/write/lseek to use 64bits size for huge file.
#ifndef _FILE_OFFSET_BITS
    #define _FILE_OFFSET_BITS 64
#endif

// for int64_t print using PRId64 format.
#ifndef __STDC_FORMAT_MACROS
    #define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>

#include <assert.h>
#define srs_assert(expression) assert(expression)

#include <stddef.h>
#include <sys/types.h>

// generated by configure.
#include <srs_auto_headers.hpp>

// free the p and set to NULL.
// p must be a T*.
#define srs_freep(p) \
    if (p) { \
        delete p; \
        p = NULL; \
    } \
    (void)0
// free the p which represents a array
#define srs_freepa(p) \
    if (p) { \
        delete[] p; \
        p = NULL; \
    } \
    (void)0

// compare
#define srs_min(a, b) (((a) < (b))? (a) : (b))
#define srs_max(a, b) (((a) < (b))? (b) : (a))

// signal defines.
#define SIGNAL_RELOAD SIGHUP

#include <string>
// replace old_str to new_str of str
extern std::string srs_string_replace(std::string str, std::string old_str, std::string new_str);
// trim char in trim_chars of str
extern std::string srs_string_trim_end(std::string str, std::string trim_chars);
// trim char in trim_chars of str
extern std::string srs_string_trim_start(std::string str, std::string trim_chars);
// remove char in remove_chars of str
extern std::string srs_string_remove(std::string str, std::string remove_chars);
// whether string end with
extern bool srs_string_ends_with(std::string str, std::string flag);

// dns resolve utility, return the resolved ip address.
extern std::string srs_dns_resolve(std::string host);
// whether system is little endian
extern bool srs_is_little_endian();

/**
* disable copy constructor of class
*/
#define disable_default_copy(className)\
    private:\
        /** \
        * disable the copy constructor and operator=, donot allow directly copy. \
        */ \
        className(const className&); \
        className& operator= (const className&)

// const time for st to convert to us
#define SRS_TIME_MILLISECONDS 1000
#define SRS_TIME_SECONDS 1000000

#endif