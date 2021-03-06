// Layer Declaration header
//
// This file is auto-generated by cmake, don't edit it.

#include "layer/convolution.h"
#include "layer/x86/convolution_x86.h"
#include "layer/vulkan/convolution_vulkan.h"
namespace ncnn {
class Convolution_final : virtual public Convolution, virtual public Convolution_x86, virtual public Convolution_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Convolution::create_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Convolution_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Convolution_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Convolution_final)
} // namespace ncnn

#include "layer/convolution.h"
#include "layer/x86/convolution_x86_avx2.h"
#include "layer/vulkan/convolution_vulkan.h"
namespace ncnn {
class Convolution_final_avx2 : virtual public Convolution, virtual public Convolution_x86_avx2, virtual public Convolution_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Convolution::create_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Convolution_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Convolution_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Convolution::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Convolution_final_avx2)
} // namespace ncnn

#include "layer/crop.h"
#include "layer/x86/crop_x86.h"
#include "layer/vulkan/crop_vulkan.h"
namespace ncnn {
class Crop_final : virtual public Crop, virtual public Crop_x86, virtual public Crop_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Crop::create_pipeline(opt); if (ret) return ret; }
        { int ret = Crop_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Crop_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Crop_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Crop_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Crop::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Crop_final)
} // namespace ncnn

#include "layer/crop.h"
#include "layer/x86/crop_x86_avx2.h"
#include "layer/vulkan/crop_vulkan.h"
namespace ncnn {
class Crop_final_avx2 : virtual public Crop, virtual public Crop_x86_avx2, virtual public Crop_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Crop::create_pipeline(opt); if (ret) return ret; }
        { int ret = Crop_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Crop_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Crop_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Crop_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Crop::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Crop_final_avx2)
} // namespace ncnn

#include "layer/deconvolution.h"
#include "layer/vulkan/deconvolution_vulkan.h"
namespace ncnn {
class Deconvolution_final : virtual public Deconvolution, virtual public Deconvolution_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Deconvolution::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Deconvolution_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Deconvolution_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Deconvolution::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Deconvolution_final)
} // namespace ncnn

#include "layer/eltwise.h"
#include "layer/x86/eltwise_x86.h"
#include "layer/vulkan/eltwise_vulkan.h"
namespace ncnn {
class Eltwise_final : virtual public Eltwise, virtual public Eltwise_x86, virtual public Eltwise_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Eltwise::create_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Eltwise_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Eltwise_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Eltwise_final)
} // namespace ncnn

#include "layer/eltwise.h"
#include "layer/x86/eltwise_x86_avx2.h"
#include "layer/vulkan/eltwise_vulkan.h"
namespace ncnn {
class Eltwise_final_avx2 : virtual public Eltwise, virtual public Eltwise_x86_avx2, virtual public Eltwise_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Eltwise::create_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Eltwise_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Eltwise_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Eltwise::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Eltwise_final_avx2)
} // namespace ncnn

#include "layer/flatten.h"
#include "layer/x86/flatten_x86.h"
#include "layer/vulkan/flatten_vulkan.h"
namespace ncnn {
class Flatten_final : virtual public Flatten, virtual public Flatten_x86, virtual public Flatten_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Flatten::create_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Flatten_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Flatten_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Flatten_final)
} // namespace ncnn

#include "layer/flatten.h"
#include "layer/x86/flatten_x86_avx2.h"
#include "layer/vulkan/flatten_vulkan.h"
namespace ncnn {
class Flatten_final_avx2 : virtual public Flatten, virtual public Flatten_x86_avx2, virtual public Flatten_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Flatten::create_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Flatten_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Flatten_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Flatten::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Flatten_final_avx2)
} // namespace ncnn

#include "layer/innerproduct.h"
#include "layer/x86/innerproduct_x86.h"
#include "layer/vulkan/innerproduct_vulkan.h"
namespace ncnn {
class InnerProduct_final : virtual public InnerProduct, virtual public InnerProduct_x86, virtual public InnerProduct_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = InnerProduct::create_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = InnerProduct_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = InnerProduct_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(InnerProduct_final)
} // namespace ncnn

#include "layer/innerproduct.h"
#include "layer/x86/innerproduct_x86_avx2.h"
#include "layer/vulkan/innerproduct_vulkan.h"
namespace ncnn {
class InnerProduct_final_avx2 : virtual public InnerProduct, virtual public InnerProduct_x86_avx2, virtual public InnerProduct_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = InnerProduct::create_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = InnerProduct_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = InnerProduct_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = InnerProduct::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(InnerProduct_final_avx2)
} // namespace ncnn

#include "layer/input.h"
namespace ncnn {
class Input_final : virtual public Input
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Input::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        { int ret = Input::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Input_final)
} // namespace ncnn

#include "layer/pooling.h"
#include "layer/x86/pooling_x86.h"
#include "layer/vulkan/pooling_vulkan.h"
namespace ncnn {
class Pooling_final : virtual public Pooling, virtual public Pooling_x86, virtual public Pooling_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Pooling::create_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Pooling_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Pooling_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Pooling_final)
} // namespace ncnn

#include "layer/pooling.h"
#include "layer/x86/pooling_x86_avx2.h"
#include "layer/vulkan/pooling_vulkan.h"
namespace ncnn {
class Pooling_final_avx2 : virtual public Pooling, virtual public Pooling_x86_avx2, virtual public Pooling_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Pooling::create_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Pooling_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Pooling_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Pooling::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Pooling_final_avx2)
} // namespace ncnn

#include "layer/relu.h"
#include "layer/x86/relu_x86.h"
#include "layer/vulkan/relu_vulkan.h"
namespace ncnn {
class ReLU_final : virtual public ReLU, virtual public ReLU_x86, virtual public ReLU_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = ReLU::create_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = ReLU_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = ReLU_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(ReLU_final)
} // namespace ncnn

#include "layer/relu.h"
#include "layer/x86/relu_x86_avx2.h"
#include "layer/vulkan/relu_vulkan.h"
namespace ncnn {
class ReLU_final_avx2 : virtual public ReLU, virtual public ReLU_x86_avx2, virtual public ReLU_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = ReLU::create_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = ReLU_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = ReLU_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = ReLU::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(ReLU_final_avx2)
} // namespace ncnn

#include "layer/scale.h"
#include "layer/x86/scale_x86.h"
#include "layer/vulkan/scale_vulkan.h"
namespace ncnn {
class Scale_final : virtual public Scale, virtual public Scale_x86, virtual public Scale_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Scale::create_pipeline(opt); if (ret) return ret; }
        { int ret = Scale_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Scale_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Scale_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Scale_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Scale::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Scale_final)
} // namespace ncnn

#include "layer/scale.h"
#include "layer/x86/scale_x86_avx2.h"
#include "layer/vulkan/scale_vulkan.h"
namespace ncnn {
class Scale_final_avx2 : virtual public Scale, virtual public Scale_x86_avx2, virtual public Scale_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Scale::create_pipeline(opt); if (ret) return ret; }
        { int ret = Scale_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Scale_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Scale_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Scale_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Scale::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Scale_final_avx2)
} // namespace ncnn

#include "layer/split.h"
namespace ncnn {
class Split_final : virtual public Split
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Split::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        { int ret = Split::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Split_final)
} // namespace ncnn

#include "layer/padding.h"
#include "layer/x86/padding_x86.h"
#include "layer/vulkan/padding_vulkan.h"
namespace ncnn {
class Padding_final : virtual public Padding, virtual public Padding_x86, virtual public Padding_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Padding::create_pipeline(opt); if (ret) return ret; }
        { int ret = Padding_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Padding_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Padding_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Padding_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Padding::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Padding_final)
} // namespace ncnn

#include "layer/padding.h"
#include "layer/x86/padding_x86_avx2.h"
#include "layer/vulkan/padding_vulkan.h"
namespace ncnn {
class Padding_final_avx2 : virtual public Padding, virtual public Padding_x86_avx2, virtual public Padding_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Padding::create_pipeline(opt); if (ret) return ret; }
        { int ret = Padding_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Padding_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Padding_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Padding_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Padding::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Padding_final_avx2)
} // namespace ncnn

#include "layer/interp.h"
#include "layer/vulkan/interp_vulkan.h"
namespace ncnn {
class Interp_final : virtual public Interp, virtual public Interp_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Interp::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Interp_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Interp_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Interp::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Interp_final)
} // namespace ncnn

#include "layer/packing.h"
#include "layer/x86/packing_x86.h"
#include "layer/vulkan/packing_vulkan.h"
namespace ncnn {
class Packing_final : virtual public Packing, virtual public Packing_x86, virtual public Packing_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Packing::create_pipeline(opt); if (ret) return ret; }
        { int ret = Packing_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Packing_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Packing_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Packing_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Packing::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Packing_final)
} // namespace ncnn

#include "layer/packing.h"
#include "layer/x86/packing_x86_avx2.h"
#include "layer/vulkan/packing_vulkan.h"
namespace ncnn {
class Packing_final_avx2 : virtual public Packing, virtual public Packing_x86_avx2, virtual public Packing_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Packing::create_pipeline(opt); if (ret) return ret; }
        { int ret = Packing_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Packing_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Packing_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Packing_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Packing::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Packing_final_avx2)
} // namespace ncnn

#include "layer/cast.h"
#include "layer/x86/cast_x86.h"
#include "layer/vulkan/cast_vulkan.h"
namespace ncnn {
class Cast_final : virtual public Cast, virtual public Cast_x86, virtual public Cast_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Cast::create_pipeline(opt); if (ret) return ret; }
        { int ret = Cast_x86::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Cast_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Cast_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Cast_x86::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Cast::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Cast_final)
} // namespace ncnn

#include "layer/cast.h"
#include "layer/x86/cast_x86_avx2.h"
#include "layer/vulkan/cast_vulkan.h"
namespace ncnn {
class Cast_final_avx2 : virtual public Cast, virtual public Cast_x86_avx2, virtual public Cast_vulkan
{
public:
    virtual int create_pipeline(const Option& opt) {
        { int ret = Cast::create_pipeline(opt); if (ret) return ret; }
        { int ret = Cast_x86_avx2::create_pipeline(opt); if (ret) return ret; }
        if (vkdev) { int ret = Cast_vulkan::create_pipeline(opt); if (ret) return ret; }
        return 0;
    }
    virtual int destroy_pipeline(const Option& opt) {
        if (vkdev) { int ret = Cast_vulkan::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Cast_x86_avx2::destroy_pipeline(opt); if (ret) return ret; }
        { int ret = Cast::destroy_pipeline(opt); if (ret) return ret; }
        return 0;
    }
};
DEFINE_LAYER_CREATOR(Cast_final_avx2)
} // namespace ncnn


