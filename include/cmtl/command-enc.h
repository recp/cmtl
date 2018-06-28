/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef cmtl_commandenc_h
#define cmtl_commandenc_h
#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "types.h"
#include "enums.h"
#include <stdint.h>

MT_EXPORT
MtRenderCommandEncoder*
mtRenderCommandEncoder(MtCommandBuffer *cmdb, MtRenderPassDesc *passDesc);

MT_EXPORT
void
mtViewport(MtRenderCommandEncoder *enc, MtViewport *viewport);

MT_EXPORT
void
mtRCEPipState(MtRenderCommandEncoder *enc, MtRenderState *pipState);

MT_EXPORT
void
mtVertexBytes(MtRenderCommandEncoder *enc,
              void                   *bytes,
              size_t                  legth,
              uint32_t                atIndex);

MT_EXPORT
void
mtRCEDrawPrimitives(MtRenderCommandEncoder *enc,
                    MtPrimitiveType         primType,
                    size_t                  vertStart,
                    size_t                  vertCount);

MT_EXPORT
void
mtEndEncoding(MtRenderCommandEncoder *enc);

#ifdef __cplusplus
}
#endif
#endif /* cmtl_commandenc_h */
