// Generated Code - DO NOT EDIT !!
// generated by 'emugen'

#ifndef GUARD_magma_decoder_context_t
#define GUARD_magma_decoder_context_t

#include "render-utils/IOStream.h"
#include "ChecksumCalculator.h"
#include "magma_server_context.h"



namespace gfxstream {

struct magma_decoder_context_t : public magma_server_context_t {

	size_t decode(void *buf, size_t bufsize, IOStream *stream, ChecksumCalculator* checksumCalc);

};

}  // namespace gfxstream

#endif  // GUARD_magma_decoder_context_t