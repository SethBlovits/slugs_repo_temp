#ifndef SLUGS_GRAPHICS_H
#define SLUGS_GRAPHICS_H

#define CINTERFACE

#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma warning(disable : 4201)
#pragma warning(disable : 4115)

#ifndef SLG_ASSERT
#include <assert.h>
#define SLG_ASSERT assert
#endif

#include "pool.h"
#include "arena.h"


#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <d3d12shader.h>
#include "d3dx12.h"

#define SLG_D3D12
#define FrameCount 2

//-----------------------------------------
// HELPER MACRO DEFININTIONS
//-----------------------------------------

#define _slg_check_defaults(param,def_val) param == 0 ? def_val : param  

#ifdef SLG_D3D12
typedef struct slg_d3d12_app_data_t{
    int width;
    int height;
    const char* name;
    HWND hwnd;
    D3D12_VIEWPORT d3d12_viewport;
    D3D12_RECT d3d12_scissor_rect;
}slg_app_data_t;
#endif

typedef enum {
    T0 = 0,
    T1 = 1,
    T2 = 2,
    T3 = 3,
    T4 = 4,
    T5 = 5,
    T6 = 6,
    T7 = 7,

    B0 = 8,
    B1 = 9,
    B2 = 10,
    B3 = 11,
    B4 = 12,
    B5 = 13,
    B6 = 14,
    B7 = 15,

    S0 = 16,
    S1 = 17,
    S2 = 18,
    S3 = 19,
    S4 = 20,
    S5 = 21,
    S6 = 22,
    S7 = 23
}SLG_BINDING_SLOT;
typedef enum {
    SLG_DEPTH_WRITE_MASK_DEFAULT = 0,
    SLG_DEPTH_WRITE_MASK_ZERO    = 1,
    SLG_DEPTH_WRITE_MASK_ALL     = 2
}SLG_DEPTH_WRITE_MASK;
typedef enum{
    SLG_FILL_MODE_DEFAULT = 0,
    SLG_FILL_MODE_SOLID = 1,
    SLG_FILL_MODE_WIREFRAME = 2
}SLG_FILL_MODE;
typedef enum {
    SLG_CULL_MODE_DEFAULT = 0,
    SLG_CULL_MODE_NONE = 1,
    SLG_CULL_MODE_FRONT = 2,
    SLG_CULL_MODE_BACK = 3
}SLG_CULL_MODE;
typedef enum{
    SLG_FACEWINDING_DEFAULT = 0,
    SLG_FACEWINDING_COUNTERCLOCKWISE = 1,
    SLG_FACEWINDING_CLOCKWISE = 2
}SLG_FACEWINDING_MODE;
typedef enum{
    SLG_BLENDMODE_DEFAULT = 0,
    SLG_BLEND_ZERO = 1,
    SLG_BLEND_ONE = 2,
    SLG_BLEND_SRC_COLOR = 3,
    SLG_BLEND_INV_SRC_COLOR	= 4,
    SLG_BLEND_SRC_ALPHA	= 5,
    SLG_BLEND_INV_SRC_ALPHA	= 6,
    SLG_BLEND_DEST_ALPHA	= 7,
    SLG_BLEND_INV_DEST_ALPHA	= 8,
    SLG_BLEND_DEST_COLOR	= 9,
    SLG_BLEND_INV_DEST_COLOR	= 10,
    SLG_BLEND_SRC_ALPHA_SAT	= 11,
    SLG_BLEND_BLEND_FACTOR	= 14,
    SLG_BLEND_INV_BLEND_FACTOR	= 15,
    SLG_BLEND_SRC1_COLOR	= 16,
    SLG_BLEND_INV_SRC1_COLOR	= 17,
    SLG_BLEND_SRC1_ALPHA	= 18,
    SLG_BLEND_INV_SRC1_ALPHA	= 19,
    SLG_BLEND_ALPHA_FACTOR	= 20,
    SLG_BLEND_INV_ALPHA_FACTOR	= 21
}SLG_BLEND_MODE;
typedef enum{
    SLG_BLEND_OP_DEFAULT = 0,
    SLG_BLEND_OP_ADD	= 1,
    SLG_BLEND_OP_SUBTRACT = 2,
    SLG_BLEND_OP_REV_SUBTRACT = 3,
    SLG_BLEND_OP_MIN	= 4,
    SLG_BLEND_OP_MAX	= 5
}SLG_BLEND_OP;
typedef enum{
    SLG_LOGIC_DEFAULT = 0,
    SLG_LOGIC_OP_CLEAR = 1,
    SLG_LOGIC_OP_SET	= 2,
    SLG_LOGIC_OP_COPY = 3,
    SLG_LOGIC_OP_COPY_INVERTED = 4,
    SLG_LOGIC_OP_NOOP = 5,
    SLG_LOGIC_OP_INVERT = 6,
    SLG_LOGIC_OP_AND = 7,
    SLG_LOGIC_OP_NAND = 8,
    SLG_LOGIC_OP_OR = 9,
    SLG_LOGIC_OP_NOR = 10,
    SLG_LOGIC_OP_XOR = 11,
    SLG_LOGIC_OP_EQUIV = 12,
    SLG_LOGIC_OP_AND_REVERSE = 13,
    SLG_LOGIC_OP_AND_INVERTED = 14,
    SLG_LOGIC_OP_OR_REVERSE = 15,
    SLG_LOGIC_OP_OR_INVERTED = 16
}SLG_LOGIC_OP;
typedef enum{
    SLG_PRIMITIVE_TOPOLOGY_TYPE_DEFAULT = 0,
    SLG_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED = 1,
    SLG_PRIMITIVE_TOPOLOGY_TYPE_POINT = 2,
    SLG_PRIMITIVE_TOPOLOGY_TYPE_LINE = 3,
    SLG_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE = 4,
    SLG_PRIMITIVE_TOPOLOGY_TYPE_PATCH = 5

}SLG_PRIMITIVE_TOPOLOGY_TYPE;
//this is a bitfield
typedef struct{
    unsigned int red_enable : 1;
    unsigned int green_enable : 1;
    unsigned int blue_enable : 1;
    unsigned int alpha_enable : 1;
    
}SLG_COLOR_WRITE_ENABLE;
typedef enum{
    SLG_CONSERVATIVE_RASTERIZATION_MODE_DEFAULT = 0,
    SLG_CONSERVATIVE_RASTERIZATION_MODE_OFF = 1,
    SLG_CONSERVATIVE_RASTERIZATION_MODE_ON = 2
}SLG_CONSERVATIVE_RASTERIZATION_MODE;
#ifdef SLG_D3D12
typedef struct slg_d3d12_desc_t{
    ID3D12Device* device;
    //ID3D12CommandAllocator* commandAllocator;
    ID3D12CommandQueue* commandQueue;
    //ID3D12GraphicsCommandList* commandList;
}slg_desc_t;
#endif

#ifdef SLG_D3D12
typedef struct slg_d3d12_frame_context_t{
    ID3D12CommandAllocator* commandAllocator;
    ID3D12GraphicsCommandList* commandList;
    ID3D12Resource* renderTarget;
    ID3D12Resource* depthTarget;
    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle;
    D3D12_CPU_DESCRIPTOR_HANDLE depthHandle;
    UINT64 fenceValue;
}slg_frame_context_t;

typedef struct slg_d3d12_framebuffer_t{
    slg_frame_context_t frame_context[FrameCount];
    UINT64 frameIndex;
    UINT64 currentFenceValue;
    IDXGISwapChain3* swapchain;
    ID3D12DescriptorHeap* rtvHeap;
    ID3D12DescriptorHeap* depthStencilHeap;
    UINT rtvDescriptorSize;
    UINT depthStencilDescriptorSize;
    //UINT frameIndex;
}slg_framebuffer_t; 
#endif
typedef struct{
    HANDLE fenceEvent;
    ID3D12Fence* fence;
    //UINT64 frameIndex;
    //UINT fenceValue[FrameCount];
}slg_fence_t;

typedef struct{//desc -> Things required to make the objects
    const char* vert_shader_name; //"VSMAIN"
    const char* vert_shader_target;//"vs_5_0"
    const char* frag_shader_name;
    const char* frag_shader_target;
    const char* filename;
    //unsigned int num_const_buffers;
}slg_shader_desc;

typedef struct slg_shader_source_data slg_shader_source_data;
#define SLG_D3D12_RESOURCE_BUFFER_LIMIT 8
#define SLG_D3D12_SAMPLER_LIMIT 8
#define SLG_MAX_ROOT_PARAMETERS 8
typedef struct{ // object data -> object type with _t
    ID3DBlob* VertexShaderBlob;
    ID3DBlob* PixelShaderBlob;
    char hlsl_name[MAX_PATH];
    char vert_shader_cso[MAX_PATH];
    char frag_shader_cso[MAX_PATH];
}slg_shader_t;
typedef struct{ // the object itself holds onto a pointer to the object
    slg_shader_t* shader_ptr;
}slg_shader;

//whenever a pipeline is made, this should be glommed onto that process so that this data can be filled in


/*struct slg_shader_source_data{//the shader needs to have a reference to this information or a copy
    
    char hlsl_name[MAX_PATH];
    char vert_shader_cso[MAX_PATH];
    char frag_shader_cso[MAX_PATH];
    slg_shader_t* shader_ptr;    
    slg_pipeline_t* pipeline_ptr;
};*/


#define SLG_D3D12_MAXIMUM_INPUT_LIMIT 16

//we need structs that will help us populate the rasterizer desc
//blend desc 
//depth stencil desc .....etc

typedef enum{
    SLG_COMPARISON_FUNC_DEFAULT = 0,
    SLG_COMPARISON_FUNC_NEVER	= 1,
    SLG_COMPARISON_FUNC_LESS	= 2,
    SLG_COMPARISON_FUNC_EQUAL	= 3,
    SLG_COMPARISON_FUNC_LESS_EQUAL	= 4,
    SLG_COMPARISON_FUNC_GREATER	= 5,
    SLG_COMPARISON_FUNC_NOT_EQUAL	= 6,
    SLG_COMPARISON_FUNC_GREATER_EQUAL	= 7,
    SLG_COMPARISON_FUNC_ALWAYS	= 8
}SLG_COMPARISON_FUNC;


typedef struct{
    
    bool depth_enable; //these will be false by default
    bool stencil_enable;

    int depth_bias;
    float depth_bias_clamp;
    float slope_scaled_depth_bias;
    SLG_COMPARISON_FUNC compare_func;
    SLG_DEPTH_WRITE_MASK write_mask;
    //bool depth_clip_enable;

}slg_depth_desc;

typedef struct{
    bool depth_enable;
    bool stencil_enable;
    SLG_COMPARISON_FUNC compare_func;
    SLG_DEPTH_WRITE_MASK write_mask;
}slg_depth_stencil_desc;
typedef struct{
    SLG_FILL_MODE fill_mode;
    SLG_CULL_MODE cull_mode;
    SLG_FACEWINDING_MODE facewinding_mode;
    SLG_CONSERVATIVE_RASTERIZATION_MODE conservative_rasterization_mode;
    int depth_bias;
    float depth_bias_clamp;
    float slope_scaled_depth_bias;
    bool depth_clip_enable;
    bool multisample_enable;
    bool antialiased_line_enable;
    unsigned int forced_sample_count;

}slg_rasterizer_desc;



typedef struct{
    bool alpha_to_coverage_enable;
    bool independent_blend_enable;

    bool blend_enable; //these are gonna be false by default
    bool logic_op_enable; //false by default

    SLG_BLEND_MODE src_blend;
    SLG_BLEND_MODE dest_blend;
    
    SLG_BLEND_MODE src_blend_alpha;
    SLG_BLEND_MODE dest_blend_alpha;
    

    SLG_BLEND_OP blend_op;
    SLG_BLEND_OP blend_op_alpha;

    SLG_LOGIC_OP logic_op;

    SLG_COLOR_WRITE_ENABLE color_write_enable;

}slg_blend_desc;


typedef enum{
    SLG_ROOT_PARAMETER_TYPE_DEFAULT = 0,
    SLG_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE = 1,
    SLG_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS = 2,
    SLG_ROOT_PARAMETER_TYPE_CBV = 3,
    SLG_ROOT_PARAMETER_TYPE_SRV = 4,
    SLG_ROOT_PARAMETER_TYPE_UAV = 5,
}SLG_ROOT_PARAMETER_TYPE;


typedef enum{
    SLG_SHADER_VISIBILITY_DEFAULT = 0,
    SLG_SHADER_VISIBILITY_VERTEX	= 1,
    SLG_SHADER_VISIBILITY_HULL	= 2,
    SLG_SHADER_VISIBILITY_DOMAIN	= 3,
    SLG_SHADER_VISIBILITY_GEOMETRY	= 4,
    SLG_SHADER_VISIBILITY_PIXEL	= 5,
    SLG_SHADER_VISIBILITY_AMPLIFICATION	= 6,
    SLG_SHADER_VISIBILITY_MESH	= 7,
    SLG_SHADER_VISIBILITY_ALL = 8
}SLG_SHADER_VISIBILITY;



typedef enum{
    SLG_DESCRIPTOR_RANGE_TYPE_DEFAULT = 0,
    SLG_DESCRIPTOR_RANGE_TYPE_SRV = 1,
    SLG_DESCIRPTOR_RANGE_TYPE_UAV = 2,
    SLG_DESCRIPTOR_RANGE_TYPE_CBV = 3,
    SLG_DESCRIPTOR_RANGE_TYPE_SAMPLER = 4
}SLG_DESCRIPTOR_RANGE_TYPE;


typedef enum{
    SLG_CONSTANT_BUFFER_VIEW_INDEX = 0,
    SLG_SHADER_RESOURCE_VIEW_INDEX = 1,
    SLG_UNORDERED_ACCESS_VIEW_INDEX = 2 
}SLG_RANGE_TYPE_PIPELINE_INDEX;

typedef struct{
    SLG_DESCRIPTOR_RANGE_TYPE range_type;
    unsigned int num_descriptors;
    unsigned int base_shader_register;
    unsigned int register_space;
}slg_descriptor_range;
#define MAX_DESCRIPTOR_RANGES 2
typedef struct{
    SLG_ROOT_PARAMETER_TYPE parameter_type;
    unsigned int register_space;
    unsigned int shader_register;
    SLG_SHADER_VISIBILITY shader_visibility;

    //for descriptor ranges if we are using that parameter type
    unsigned int num_descriptor_ranges;
    slg_descriptor_range ranges[MAX_DESCRIPTOR_RANGES]; // we are gonna set two as the maximum amount of ranges

}slg_root_parameter;



typedef struct{//things required to populate/make pipeline    

    slg_shader shader;


    slg_rasterizer_desc rasterizer_desc;
    slg_depth_stencil_desc depth_stencil_desc;
    slg_blend_desc blend_desc;

    slg_root_parameter root_parameters[SLG_MAX_ROOT_PARAMETERS];

    //SLG_FILL_MODE fill_mode; 
    //SLG_CULL_MODE cull_mode; 
    //SLG_FACEWINDING_MODE face_winding; 

    //bool multi_sample_enable; //false by default
    unsigned int sample_count;
    //bool antiialiased_line_enable; //false by default
    //unsigned int forced_sample_count; //zero is default
    
    //SLG_CONSERVATIVE_RASTERIZATION_MODE conservative_rasterization_mode;
    SLG_PRIMITIVE_TOPOLOGY_TYPE primitive_topology_type;

    unsigned int sample_mask;
    unsigned int num_render_targets; // this might not be necessary to include


    //temp format override
    DXGI_FORMAT* format_overrides;
    int num_overrides;

}slg_pipeline_desc;
/*
typedef struct{
    ID3D12PipelineState* pipeline_state;
    ID3D12RootSignature* root_signature;
}slg_pipeline_t;*/
#ifdef SLG_D3D12
typedef struct slg_d3d12_pipeline_t{
    ID3D12PipelineState* pipeline_state;
    ID3D12RootSignature* root_signature;
    #ifdef SLG_HOT_RELOADING
    D3D12_GRAPHICS_PIPELINE_STATE_DESC pso_state_desc;
    D3D12_INPUT_ELEMENT_DESC input_element_descs[SLG_D3D12_MAXIMUM_INPUT_LIMIT];
    char sematic_names[SLG_D3D12_MAXIMUM_INPUT_LIMIT][1024];//temp number for the characters
    UINT num_input_elements;
    slg_shader_t* shader_ptr;
    #endif
}slg_pipeline_t;
#endif

typedef struct{
    slg_pipeline_t* data_ptr;
}slg_pipeline;


#ifdef SLG_HOT_RELOADING

    typedef struct{
        ID3D12PipelineState* pip;
        UINT64 fence;

    }pipeline_fence_bundle;

    struct slg_old_pip_queue{
        pipeline_fence_bundle pip_queue[25];
        int num_pips;
        int max_pips;
    };
    struct slg_old_pip_queue old_queue;
#endif


enum buffer_type{
    THROW,
    VERTEX,
    INDEX
};


typedef enum{
    SLG_DESCRIPTOR_HEAP_TYPE_DEFAULT = 0,
    SLG_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV	= 1,
    SLG_DESCRIPTOR_HEAP_TYPE_SAMPLER	= 2,
    SLG_DESCRIPTOR_HEAP_TYPE_RTV	= 3,
    SLG_DESCRIPTOR_HEAP_TYPE_DSV	= 4,
    SLG_DESCRIPTOR_HEAP_TYPE_NUM_TYPES = 5  

}SLG_DESCRIPTOR_HEAP_TYPE;


typedef enum{
    SLG_DESCRIPTOR_HEAP_FLAG_DEFAULT	= 0,
    SLG_DESCRIPTOR_HEAP_FLAG_NONE = 1,
    SLG_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE = 2
}SLG_DESCRIPTOR_HEAP_FLAG;


typedef struct{
    unsigned int num_buffers;
    SLG_DESCRIPTOR_HEAP_TYPE descriptor_heap_type;
    SLG_DESCRIPTOR_HEAP_FLAG Flags;
}slg_heap_desc;
typedef struct{
    ID3D12DescriptorHeap* heap;
    SLG_DESCRIPTOR_HEAP_TYPE descriptor_heap_type;
}slg_heap_t;
typedef struct{
    slg_heap_t* data_ptr;
}slg_heap;

typedef enum{
    SLG_BUFFER_USAGE_DEFAULT = 0,
    SLG_BUFFER_USAGE_CONSTANT_BUFFER = 1,
}SLG_BUFFER_USAGE;

typedef struct{
    void* buffer;
    UINT buffer_size;
    UINT buffer_stride;
    SLG_BUFFER_USAGE usage;
}slg_buffer_desc;

typedef struct{
    ID3D12Resource* buffer; //will need to be released
    UINT buffer_size; //the size of the entire buffer
    UINT buffer_stride;
}slg_buffer_t;

typedef struct{
    slg_buffer_t* data_ptr;
}slg_buffer;

typedef enum{
    SLG_TEXTURE_TYPE_DEFAULT = 0,
    SLG_TEXTURE_TYPE_2D = 1,
    SLG_TEXTURE_TYPE_CUBEMAP = 2
}SLG_TEXTURE_TYPE;

typedef struct{
    void* texture;
    unsigned int width;
    unsigned int height;
    SLG_TEXTURE_TYPE tex_type;
    unsigned int pixel_size;
}slg_texture_desc;

typedef struct{
    ID3D12Resource* texture;
}slg_texture_t;


typedef struct{
    slg_texture_t* data_ptr;
}slg_texture;

typedef struct slg_bindings_t{
    slg_buffer vertex_buffer;
    slg_buffer index_buffer;
    slg_buffer const_buffer[SLG_D3D12_RESOURCE_BUFFER_LIMIT];
    slg_texture srv_buffer[SLG_D3D12_RESOURCE_BUFFER_LIMIT];
    slg_heap cbv_srv_uav_heap;
    size_t cbv_heap_start;
    size_t srv_heap_start;
    size_t uav_heap_start;
    unsigned int num_cbv_heap;
    slg_heap sampler_heap;
    unsigned int num_samplers_heap;
}slg_bindings_t;


typedef struct{
    slg_bindings_t* data_ptr;
}slg_bindings;

typedef void (*UniformBinder)(void* uniforms, slg_bindings* bind);
typedef struct{
    void* uniforms;
    UniformBinder bind_func;
}Uniforms;
typedef struct{
    slg_buffer vertex_buffer;
    slg_buffer index_buffer;
    //slg_buffer resource_buffer[SLG_D3D12_RESOURCE_BUFFER_LIMIT*3]; 
    //slg_buffer const_buffer[SLG_D3D12_RESOURCE_BUFFER_LIMIT];
    // /slg_texture tex_buffer[SLG_D3D12_RESOURCE_BUFFER_LIMIT];
    Uniforms uniforms;
    
}slg_bindings_desc;

///////////////////////////////////////////////////////
////                TBD TESTING AREA

typedef struct{//this can probably hold the shader information and pipeline stuff maybe?
    slg_pipeline* pip;
    slg_shader* shader;
    //Vector3 specular;
    //Vector3 ambient;
    //Vector3 diffuse;
    float shininess; 
    slg_texture albedo;
    slg_texture normal_map;
}slg_material;
typedef struct{//there should always be these three components in a mesh
    /*void* vertex_buffer;
    size_t vert_buffer_size;
    size_t vert_buffer_stride;
    void* index_buffer;
    size_t index_buffer_size;*/
    slg_buffer vertex_buffer;
    slg_buffer index_buffer;
}slg_mesh;
typedef struct{
    slg_buffer mvp;
    //leave room for some of the other matrices that are needed later
    //like the bone transforms and things like that 
}slg_transform;
typedef struct{
    slg_material mat;
    slg_mesh mesh;
    slg_transform transform;
    slg_bindings bind;
}slg_graphics_object;


////////////////////////////////////////////////////////






/*
DECLARE THE POOLS FOR ALL THE OBJECTS WE NEED
*/
typedef struct{
    unsigned char* shaderPoolBackingBuffer;
    Pool shader_pool;
    //unsigned char* shaderFileReferenceBackingBuffer;
    //Pool shaderFileReferencePool;
    unsigned char* pipelinePoolBackingBuffer;
    Pool pipeline_pool;
    unsigned char* bufferPoolBackingBuffer;
    Pool buffer_pool;
    unsigned char* heapPoolBackingBuffer;
    Pool heap_pool;
    unsigned char* texturePoolBackingBuffer;
    Pool texture_pool;
    unsigned char* bindingPoolBackingBuffer;
    Pool binding_pool;
}slg_pools_t;
slg_pools_t slg_pools;

struct{
    slg_desc_t desc;
    slg_framebuffer_t frame_buf;
    slg_app_data_t appdata;
    slg_fence_t fence;
}slg_d3d12_state = {0};


//DECLARE THE MEMORY ARENA
Arena slg_arena;


//FUNCTION_PROTOTYPES

//D3D12 ENUM CONVERSIONS
static D3D12_FILL_MODE _slg_d3d12_convert_fill_mode(SLG_FILL_MODE);
static D3D12_CULL_MODE _slg_d3d12_convert_cull_mode(SLG_CULL_MODE);
static D3D12_CONSERVATIVE_RASTERIZATION_MODE _slg_d3d12_convert_conservative_rasterization_mode(SLG_CONSERVATIVE_RASTERIZATION_MODE);
static D3D12_PRIMITIVE_TOPOLOGY_TYPE _slg_d3d12_convert_primitive_topology_type(SLG_PRIMITIVE_TOPOLOGY_TYPE);
static D3D12_BLEND _slg_d3d12_convert_blend_mode(SLG_BLEND_MODE);
static D3D12_BLEND_OP _slg_d3d12_convert_blend_op(SLG_BLEND_OP);
static D3D12_LOGIC_OP _slg_d3d12_convert_logic_op(SLG_LOGIC_OP);
static uint8_t _slg_d3d12_convert_color_write_enable(SLG_COLOR_WRITE_ENABLE);
static D3D12_DEPTH_WRITE_MASK _slg_d3d12_convert_depth_write_mask(SLG_DEPTH_WRITE_MASK);
static D3D12_COMPARISON_FUNC _slg_d3d12_convert_comparison_func(SLG_COMPARISON_FUNC);
static D3D12_DESCRIPTOR_HEAP_FLAGS _slg_d3d12_convert_descriptor_heap_flags(SLG_DESCRIPTOR_HEAP_FLAG);
static D3D12_DESCRIPTOR_HEAP_TYPE _slg_d3d12_convert_descriptor_heap_type(SLG_DESCRIPTOR_HEAP_TYPE);
static D3D12_DESCRIPTOR_RANGE_TYPE _slg_d3d12_convert_descriptor_range_type(SLG_DESCRIPTOR_RANGE_TYPE);
static D3D12_SHADER_VISIBILITY _slg_d3d12_convert_shader_visibility(SLG_SHADER_VISIBILITY);
static D3D12_ROOT_PARAMETER_TYPE _slg_d3d12_convert_root_parameter_type(SLG_ROOT_PARAMETER_TYPE);
static D3D12_RESOURCE_DIMENSION _slg_d3d12_convert_resource_dimension(SLG_TEXTURE_TYPE tex_type);
static int _slg_getArrraySizeFromTexType(SLG_TEXTURE_TYPE tex_type);
static bool _slg_d3d12_convert_facewinding(SLG_FACEWINDING_MODE mode);
//D3D12 UTILITY FUNCTIONS
void d3d12_throwIfFailed(HRESULT);
void d3d12_throwIfFailed_Error(HRESULT, ID3DBlob*);
void d3d12_GetAssetFullPath(const char*,LPWSTR);
void d3d12_waitForGPU(void);
void d3d12_moveToNextFrame(void);
inline void d3d12_memcpySubresource(const D3D12_MEMCPY_DEST*,const D3D12_SUBRESOURCE_DATA*,SIZE_T,UINT,UINT);
inline uint64_t d3d12_updateSubresources_impl(
    ID3D12GraphicsCommandList*,
    ID3D12Resource*,
    ID3D12Resource*,
    UINT,
    UINT,
    uint64_t,
    const D3D12_PLACED_SUBRESOURCE_FOOTPRINT*,
    const UINT*,
    const uint64_t*,
    const D3D12_SUBRESOURCE_DATA*
);
inline uint64_t d3d12_updateSubresources(
    ID3D12GraphicsCommandList*,
    ID3D12Resource*,
    ID3D12Resource*,
    uint64_t,
    unsigned int,
    unsigned int,
    const D3D12_SUBRESOURCE_DATA*
);

//SLG D3D12 CREATION FUNCTIONS
void _slg_d3d12_CreateCommandAllocator(ID3D12Device*,ID3D12CommandAllocator**);
void _slg_d3d12_CreateCommandList(ID3D12Device*, ID3D12CommandAllocator*,ID3D12GraphicsCommandList**);
void _slg_d3d12_CreateDepthBuffer(slg_desc_t*, slg_app_data_t*, slg_framebuffer_t*);
void _slg_d3d12_CreateFence(void);

//SLG FUNCTIONS(DX12 IMPL)

static inline slg_shader _slg_d3d12_make_shader(slg_shader_desc*);
static inline slg_pipeline _slg_d3d12_make_pipeline(slg_pipeline_desc*);
static inline slg_bindings _slg_d3d12_make_bindings(slg_bindings_desc*);
static inline slg_texture _slg_d3d12_make_texture(slg_texture_desc*);
void _slg_d3d12_close_setup(void);
void _slg_d3d12_begin_pass(void);
void _slg_d3d12_set_pipeline(slg_pipeline*);
void _slg_d3d12_setup(void);
void _slg_d3d12_set_bindings(slg_bindings*);
void _slg_d3d12_draw(unsigned int,unsigned int,unsigned int,int,unsigned int);
void _slg_d3d12_submit_draw(void);


//SLG FUNCTIONS
slg_shader slg_make_shader(slg_shader_desc*);
void slg_default_pipeline_desc(slg_pipeline_desc*);
slg_pipeline slg_make_pipeline(slg_pipeline_desc*);
slg_heap slg_make_heap(slg_heap_desc*);
slg_texture slg_make_texture(slg_texture_desc*);
slg_buffer slg_make_buffer(slg_buffer_desc*);
void slg_update_buffer(slg_buffer, void*, unsigned int);
slg_bindings slg_make_bindings(slg_bindings_desc*);
void slg_setup(void);
void slg_close_setup(void);
void slg_begin_pass(void);
void slg_set_pipeline(slg_pipeline*);
void slg_draw(unsigned int,unsigned int,unsigned int,int,unsigned int);
void slg_submit_draw(void);
//POOLS-MEMORY MANAGEMENT(DX12)
static void _slg_d3d12_destroy_shader_pool(Pool*);
static void _slg_d3d12_destroy_pipeline_pool(Pool*); 
static void _slg_d3d12_destroy_buffer_pool(Pool*);
static void _slg_d3d12_destroy_heap_pool(Pool*);
static void _slg_d3d12_destroy_texture_pool(Pool*);
void _slg_d3d12_destroy_desc(void);
void _slg_d3d12_destroy_framebuffer(void);
void _slg_d3d12_destroy_fence(void);
static void _slg_release_pool_memory(void);
//POOLS SETUP EXTERN
void slg_init_pools(void);
void slg_cleanup(void);


#endif

#ifdef SLUGS_IMPLEMENTATION



//=========================================================================================//
//                                                                                         //
//                                  DX12 BACKEND                                           //     
//                                                                                         // 
//=========================================================================================//

//D3D12 ENUM CONVERSIONS
static D3D12_FILL_MODE _slg_d3d12_convert_fill_mode(SLG_FILL_MODE mode){
    switch(mode){
        case(SLG_FILL_MODE_SOLID):
            return D3D12_FILL_MODE_SOLID;
            break;
        case(SLG_FILL_MODE_WIREFRAME):
            return D3D12_FILL_MODE_WIREFRAME;
            break;
        default:
            SLG_ASSERT(false && "improper converion in _slg_d3d12_convert_fill_mode");
            //return 0;
    }
    return D3D12_FILL_MODE_SOLID;
}

static D3D12_CULL_MODE _slg_d3d12_convert_cull_mode(SLG_CULL_MODE mode){
    switch(mode){
        case(SLG_CULL_MODE_NONE):
            return D3D12_CULL_MODE_NONE;
            break;
        case(SLG_CULL_MODE_FRONT):
            return D3D12_CULL_MODE_FRONT;
            break;
        case(SLG_CULL_MODE_BACK):
            return D3D12_CULL_MODE_BACK;
            break;
        default:
            SLG_ASSERT(false && "improper conversion in _slg_d3d312_convert_cull_mode");
            //return 0;
    }
    return D3D12_CULL_MODE_NONE;
}

static D3D12_BLEND _slg_d3d12_convert_blend_mode(SLG_BLEND_MODE mode) {
    switch (mode) {
        case SLG_BLENDMODE_DEFAULT:      return D3D12_BLEND_ONE;
        case SLG_BLEND_ZERO:             return D3D12_BLEND_ZERO;
        case SLG_BLEND_ONE:              return D3D12_BLEND_ONE;
        case SLG_BLEND_SRC_COLOR:        return D3D12_BLEND_SRC_COLOR;
        case SLG_BLEND_INV_SRC_COLOR:    return D3D12_BLEND_INV_SRC_COLOR;
        case SLG_BLEND_SRC_ALPHA:        return D3D12_BLEND_SRC_ALPHA;
        case SLG_BLEND_INV_SRC_ALPHA:    return D3D12_BLEND_INV_SRC_ALPHA;
        case SLG_BLEND_DEST_ALPHA:       return D3D12_BLEND_DEST_ALPHA;
        case SLG_BLEND_INV_DEST_ALPHA:   return D3D12_BLEND_INV_DEST_ALPHA;
        case SLG_BLEND_DEST_COLOR:       return D3D12_BLEND_DEST_COLOR;
        case SLG_BLEND_INV_DEST_COLOR:   return D3D12_BLEND_INV_DEST_COLOR;
        case SLG_BLEND_SRC_ALPHA_SAT:    return D3D12_BLEND_SRC_ALPHA_SAT;
        case SLG_BLEND_BLEND_FACTOR:     return D3D12_BLEND_BLEND_FACTOR;
        case SLG_BLEND_INV_BLEND_FACTOR: return D3D12_BLEND_INV_BLEND_FACTOR;
        case SLG_BLEND_SRC1_COLOR:       return D3D12_BLEND_SRC1_COLOR;
        case SLG_BLEND_INV_SRC1_COLOR:   return D3D12_BLEND_INV_SRC1_COLOR;
        case SLG_BLEND_SRC1_ALPHA:       return D3D12_BLEND_SRC1_ALPHA;
        case SLG_BLEND_INV_SRC1_ALPHA:   return D3D12_BLEND_INV_SRC1_ALPHA;
        case SLG_BLEND_ALPHA_FACTOR:     return D3D12_BLEND_ALPHA_FACTOR;     
        case SLG_BLEND_INV_ALPHA_FACTOR: return D3D12_BLEND_INV_ALPHA_FACTOR; // same as INV_BLEND_FACTOR
        default:
            SLG_ASSERT(false && "improper conversion in _slg_d3d12_convert_blend_mode");
            return D3D12_BLEND_ZERO; // safe fallback
    }
}
static D3D12_LOGIC_OP _slg_d3d12_convert_logic_op(SLG_LOGIC_OP logic_op){
    switch (logic_op) {
        case SLG_LOGIC_OP_CLEAR:         return D3D12_LOGIC_OP_CLEAR;
        case SLG_LOGIC_OP_SET:           return D3D12_LOGIC_OP_SET;
        case SLG_LOGIC_OP_COPY:          return D3D12_LOGIC_OP_COPY;
        case SLG_LOGIC_OP_COPY_INVERTED: return D3D12_LOGIC_OP_COPY_INVERTED;
        case SLG_LOGIC_OP_NOOP:          return D3D12_LOGIC_OP_NOOP;
        case SLG_LOGIC_OP_INVERT:        return D3D12_LOGIC_OP_INVERT;
        case SLG_LOGIC_OP_AND:           return D3D12_LOGIC_OP_AND;
        case SLG_LOGIC_OP_NAND:          return D3D12_LOGIC_OP_NAND;
        case SLG_LOGIC_OP_OR:            return D3D12_LOGIC_OP_OR;
        case SLG_LOGIC_OP_NOR:           return D3D12_LOGIC_OP_NOR;
        case SLG_LOGIC_OP_XOR:           return D3D12_LOGIC_OP_XOR;
        case SLG_LOGIC_OP_EQUIV:         return D3D12_LOGIC_OP_EQUIV;
        case SLG_LOGIC_OP_AND_REVERSE:   return D3D12_LOGIC_OP_AND_REVERSE;
        case SLG_LOGIC_OP_AND_INVERTED:  return D3D12_LOGIC_OP_AND_INVERTED;
        case SLG_LOGIC_OP_OR_REVERSE:    return D3D12_LOGIC_OP_OR_REVERSE;
        case SLG_LOGIC_OP_OR_INVERTED:   return D3D12_LOGIC_OP_OR_INVERTED;
        default:
            SLG_ASSERT(false && "improper conversion in _slg_d3d12_convert_logic_op");
            return D3D12_LOGIC_OP_NOOP; // safe fallback
    }
}

static D3D12_BLEND_OP _slg_d3d12_convert_blend_op(SLG_BLEND_OP op){
    switch(op){
        case(SLG_BLEND_OP_ADD): return D3D12_BLEND_OP_ADD;
        case(SLG_BLEND_OP_SUBTRACT): return D3D12_BLEND_OP_SUBTRACT;
        case(SLG_BLEND_OP_REV_SUBTRACT): return D3D12_BLEND_OP_REV_SUBTRACT;
        case(SLG_BLEND_OP_MIN): return D3D12_BLEND_OP_MIN;
        case(SLG_BLEND_OP_MAX): return D3D12_BLEND_OP_MAX;
        default:
            SLG_ASSERT(false && "improper conversion in _slg_d3d12_convert_blend_op");
            return D3D12_BLEND_OP_ADD; // i think this might be a bad idea 
    }
}

static D3D12_DESCRIPTOR_HEAP_FLAGS _slg_d3d12_convert_descriptor_heap_flags(SLG_DESCRIPTOR_HEAP_FLAG arg){
    switch(arg){
        case(SLG_DESCRIPTOR_HEAP_FLAG_NONE): return D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        case(SLG_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE): return D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        default:
            SLG_ASSERT(false && "improper input in _slg_d3d12_convert_descriptor_heap_flags");
            return D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    }
}

static D3D12_DESCRIPTOR_HEAP_TYPE _slg_d3d12_convert_descriptor_heap_type(SLG_DESCRIPTOR_HEAP_TYPE arg){
    switch(arg){
        case(SLG_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV): return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        case(SLG_DESCRIPTOR_HEAP_TYPE_SAMPLER): return D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
        case(SLG_DESCRIPTOR_HEAP_TYPE_RTV): return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        case(SLG_DESCRIPTOR_HEAP_TYPE_DSV): return D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
        case(SLG_DESCRIPTOR_HEAP_TYPE_NUM_TYPES): return D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES;
        default:
            SLG_ASSERT(false && "improper input in _slg_d3d12_convert_descriptor_heap_type");
            return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

    } 
}

static D3D12_DESCRIPTOR_RANGE_TYPE _slg_d3d12_convert_descriptor_range_type(SLG_DESCRIPTOR_RANGE_TYPE arg){
    switch(arg){
        case(SLG_DESCRIPTOR_RANGE_TYPE_SRV): return D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
        case(SLG_DESCIRPTOR_RANGE_TYPE_UAV): return D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
        case(SLG_DESCRIPTOR_RANGE_TYPE_CBV): return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
        case(SLG_DESCRIPTOR_RANGE_TYPE_SAMPLER): return D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
        default:
            SLG_ASSERT(false && "improper input into _slg_d3d12_convert_descriptor_range_type");
            return D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    }
}

static D3D12_SHADER_VISIBILITY _slg_d3d12_convert_shader_visibility(SLG_SHADER_VISIBILITY arg){
    switch(arg){
        case(SLG_SHADER_VISIBILITY_VERTEX): return D3D12_SHADER_VISIBILITY_VERTEX;
        case(SLG_SHADER_VISIBILITY_HULL): return D3D12_SHADER_VISIBILITY_HULL;
        case(SLG_SHADER_VISIBILITY_DOMAIN): return D3D12_SHADER_VISIBILITY_DOMAIN;
        case(SLG_SHADER_VISIBILITY_GEOMETRY): return D3D12_SHADER_VISIBILITY_GEOMETRY;
        case(SLG_SHADER_VISIBILITY_PIXEL): return D3D12_SHADER_VISIBILITY_PIXEL;
        case(SLG_SHADER_VISIBILITY_AMPLIFICATION): return D3D12_SHADER_VISIBILITY_AMPLIFICATION;
        case(SLG_SHADER_VISIBILITY_MESH): return D3D12_SHADER_VISIBILITY_MESH;
        case(SLG_SHADER_VISIBILITY_ALL):return D3D12_SHADER_VISIBILITY_ALL;
        default:
            SLG_ASSERT(false && "invalid input into _slg_d3d12_convert_shader_visibility");
            return D3D12_SHADER_VISIBILITY_VERTEX;
    }
}

static D3D12_ROOT_PARAMETER_TYPE _slg_d3d12_convert_root_parameter_type(SLG_ROOT_PARAMETER_TYPE arg){
    switch(arg){
        case(SLG_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE): return D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
        case(SLG_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS): return D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS;
        case(SLG_ROOT_PARAMETER_TYPE_CBV): return D3D12_ROOT_PARAMETER_TYPE_CBV;
        case(SLG_ROOT_PARAMETER_TYPE_SRV): return D3D12_ROOT_PARAMETER_TYPE_SRV;
        case(SLG_ROOT_PARAMETER_TYPE_UAV): return D3D12_ROOT_PARAMETER_TYPE_UAV;
        default:
            SLG_ASSERT(false && "invalid input into _slg_d3d12_convert_root_paramter_type");
            return D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    }
}

static D3D12_CONSERVATIVE_RASTERIZATION_MODE _slg_d3d12_convert_conservative_rasterization_mode(SLG_CONSERVATIVE_RASTERIZATION_MODE arg){
    switch(arg){
        case(SLG_CONSERVATIVE_RASTERIZATION_MODE_OFF): return D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
        case(SLG_CONSERVATIVE_RASTERIZATION_MODE_ON): return D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON;
        default:
            SLG_ASSERT(false && "improper conversion in _slg_d3d12_convert_conservative_rasterization_mode");
            return D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    }
}

static uint8_t _slg_d3d12_convert_color_write_enable(SLG_COLOR_WRITE_ENABLE color_bits){
    uint8_t enabled=0;
    enabled |= color_bits.red_enable;
    enabled |= color_bits.green_enable << 1;
    enabled |= color_bits.blue_enable << 2;
    enabled |= color_bits.alpha_enable << 3;

    return enabled;
    
}

static D3D12_PRIMITIVE_TOPOLOGY_TYPE _slg_d3d12_convert_primitive_topology_type(SLG_PRIMITIVE_TOPOLOGY_TYPE arg){
    switch(arg){
        case(SLG_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED): return D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED;
        case(SLG_PRIMITIVE_TOPOLOGY_TYPE_POINT): return D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT;
        case(SLG_PRIMITIVE_TOPOLOGY_TYPE_LINE): return D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE;
        case(SLG_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE): return D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        case(SLG_PRIMITIVE_TOPOLOGY_TYPE_PATCH): return D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH;
        default:
            SLG_ASSERT(false && "improper conversion in _slg_convert_primitive_topology_type");
            return D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    }
}

static D3D12_DEPTH_WRITE_MASK _slg_d3d12_convert_depth_write_mask(SLG_DEPTH_WRITE_MASK mask) {
    switch (mask) {
        case SLG_DEPTH_WRITE_MASK_ZERO: return D3D12_DEPTH_WRITE_MASK_ZERO;
        case SLG_DEPTH_WRITE_MASK_ALL: return D3D12_DEPTH_WRITE_MASK_ALL;
        case SLG_DEPTH_WRITE_MASK_DEFAULT:
        default:
            return D3D12_DEPTH_WRITE_MASK_ALL; // D3D default
    }
}

static D3D12_COMPARISON_FUNC _slg_d3d12_convert_comparison_func(SLG_COMPARISON_FUNC func){
    switch(func){
        case SLG_COMPARISON_FUNC_NEVER: return D3D12_COMPARISON_FUNC_NEVER;
        case SLG_COMPARISON_FUNC_LESS: return D3D12_COMPARISON_FUNC_LESS;
        case SLG_COMPARISON_FUNC_EQUAL: return D3D12_COMPARISON_FUNC_EQUAL;
        case SLG_COMPARISON_FUNC_LESS_EQUAL: return D3D12_COMPARISON_FUNC_LESS_EQUAL;
        case SLG_COMPARISON_FUNC_GREATER: return D3D12_COMPARISON_FUNC_GREATER;
        case SLG_COMPARISON_FUNC_NOT_EQUAL: return D3D12_COMPARISON_FUNC_NOT_EQUAL;
        case SLG_COMPARISON_FUNC_GREATER_EQUAL: return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
        case SLG_COMPARISON_FUNC_ALWAYS: return D3D12_COMPARISON_FUNC_ALWAYS;
        case SLG_COMPARISON_FUNC_DEFAULT:
        default:
            return D3D12_COMPARISON_FUNC_LESS_EQUAL; // D3D default
    }
}
DXGI_FORMAT _slg_d3d12_D3DCOMPONENTTYPE_to_DXGIFORMAT(D3D_REGISTER_COMPONENT_TYPE component_type,BYTE mask){
    switch(component_type){
        case(D3D_REGISTER_COMPONENT_FLOAT32):
            switch(mask){
                case(0x1): return DXGI_FORMAT_R32_FLOAT;
                case(0x3): return DXGI_FORMAT_R32G32_FLOAT;
                case(0x7): return DXGI_FORMAT_R32G32B32_FLOAT;
                case(0xF): return DXGI_FORMAT_R32G32B32A32_FLOAT;
            }
        break;
        case(D3D_REGISTER_COMPONENT_SINT32):
            switch(mask){
                case(0x1): return DXGI_FORMAT_R32_SINT;
                case(0x2): return DXGI_FORMAT_R32G32_SINT;
                case(0x7): return DXGI_FORMAT_R32G32B32_SINT;
                case(0xF): return DXGI_FORMAT_R32G32B32A32_SINT; 
            }
        break;
        case(D3D_REGISTER_COMPONENT_UINT32):
            switch(mask){
                case(0x1): return DXGI_FORMAT_R32_UINT;
                case(0x2): return DXGI_FORMAT_R32G32_UINT;
                case(0x7): return DXGI_FORMAT_R32G32B32_UINT;
                case(0xF): return DXGI_FORMAT_R32G32B32A32_UINT; 
            }
        break;
        default:
            return DXGI_FORMAT_UNKNOWN;
    }
    return DXGI_FORMAT_UNKNOWN;
}
int _slg_getArrraySizeFromTexType(SLG_TEXTURE_TYPE tex_type){
    switch(tex_type){
        case(SLG_TEXTURE_TYPE_2D): return 1;
        case(SLG_TEXTURE_TYPE_CUBEMAP): return 6;
        default: return 1;
    }
    //return 1;

}
static D3D12_RESOURCE_DIMENSION _slg_d3d12_convert_resource_dimension(SLG_TEXTURE_TYPE tex_type){
    switch(tex_type){
        case(SLG_TEXTURE_TYPE_2D): return D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        case(SLG_TEXTURE_TYPE_CUBEMAP): return D3D12_RESOURCE_DIMENSION_TEXTURE2D;
        default: return D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    }
}
static bool _slg_d3d12_convert_facewinding(SLG_FACEWINDING_MODE mode){
    switch(mode){
        case(SLG_FACEWINDING_COUNTERCLOCKWISE):
            return false;
            break;
        case(SLG_FACEWINDING_CLOCKWISE):
            return true;
            break;
        default:
            SLG_ASSERT(false && "invalid input into _slg_d3d12_convert_facewinding");
    }
    return false;
}
//STARTING D3D12 UTILTITY FUNCTIONS

void d3d12_throwIfFailed(HRESULT hr){
    if(FAILED(hr)){
        
        SLG_ASSERT(false);
        exit(EXIT_FAILURE);
    }
}
void d3d12_throwIfFailed_Error(HRESULT hr,ID3DBlob* Error){
    if(FAILED(hr)){
        OutputDebugStringA((char*)Error->lpVtbl->GetBufferPointer(Error));
        SLG_ASSERT(false);
        exit(EXIT_FAILURE);
    }
}
void d3d12_GetAssetFullPath(const char* filename,LPWSTR out_string){
    char fullFileName[MAX_PATH];

    GetFullPathName(filename,MAX_PATH,fullFileName,NULL);

    //const wchar_t wString[MAX_PATH]; //= (const wchar_t*)arena_alloc(&slg_arena,4096*sizeof(const wchar_t));
    MultiByteToWideChar(CP_ACP,0,(LPCCH)fullFileName,-1,out_string,MAX_PATH);

    //return (LPCWSTR)wString;
}

void d3d12_waitForGPU(){
    
    
    slg_desc_t* desc = &slg_d3d12_state.desc;
    slg_fence_t* fence = &slg_d3d12_state.fence;
    slg_frame_context_t* frame_context = &slg_d3d12_state.frame_buf.frame_context[slg_d3d12_state.frame_buf.frameIndex];
    

    //d3d12_throwIfFailed(desc->commandQueue->lpVtbl->Signal(desc->commandQueue,fence->fence,fence->fenceValue[fence->frameIndex]));
    d3d12_throwIfFailed(desc->commandQueue->lpVtbl->Signal(desc->commandQueue,fence->fence,frame_context->fenceValue));

    d3d12_throwIfFailed(fence->fence->lpVtbl->SetEventOnCompletion(fence->fence,frame_context->fenceValue,fence->fenceEvent));
    WaitForSingleObjectEx(fence->fenceEvent,INFINITE,false);

    //fence->fenceValue[fence->frameIndex]++;
    //frame_context->fenceValue+

}
void d3d12_moveToNextFrame() {
    slg_desc_t* desc = &slg_d3d12_state.desc;
    slg_fence_t* fence = &slg_d3d12_state.fence;
    slg_framebuffer_t* framebuffer = &slg_d3d12_state.frame_buf;
    slg_frame_context_t* current_frame_context = &slg_d3d12_state.frame_buf.frame_context[slg_d3d12_state.frame_buf.frameIndex];

    //const UINT64 currentFenceValue = current_frame_context->fenceValue;
    current_frame_context->fenceValue = framebuffer->currentFenceValue;
    // Signal the GPU with current frame's fence value
    d3d12_throwIfFailed(desc->commandQueue->lpVtbl->Signal(desc->commandQueue, fence->fence, framebuffer->currentFenceValue));

    // Compute the next frame index
    UINT nextFrameIndex = (framebuffer->frameIndex + 1) % FrameCount;
    slg_frame_context_t* next_frame_context = &slg_d3d12_state.frame_buf.frame_context[nextFrameIndex];
    // Wait until the GPU has finished with the next frame
    if (fence->fence->lpVtbl->GetCompletedValue(fence->fence) < next_frame_context->fenceValue) {
        d3d12_throwIfFailed(fence->fence->lpVtbl->SetEventOnCompletion(
            fence->fence,
            next_frame_context->fenceValue,
            fence->fenceEvent
        ));
        WaitForSingleObjectEx(fence->fenceEvent, INFINITE, false);
    }

    framebuffer->currentFenceValue++;
    // Update fence value for this frame
    //next_frame_context->fenceValue = currentFenceValue + 1;

    // Move to next frame
    framebuffer->frameIndex = nextFrameIndex;
}

inline void d3d12_memcpySubresource(
    const D3D12_MEMCPY_DEST* pDest,
    const D3D12_SUBRESOURCE_DATA* pSrc,
    SIZE_T RowSizeInBytes,
    UINT NumRows,
    UINT NumSlices)
{
    for(UINT z = 0;z<NumSlices;++z){
        BYTE* pDestSlice = (BYTE*)pDest->pData + pDest->SlicePitch * z;
        const BYTE* pSrcSlice = (const BYTE*)pSrc->pData + pSrc->SlicePitch * (LONG_PTR)z;
        for(UINT y = 0; y < NumRows;++y){
            memcpy(pDestSlice + pDest->RowPitch * y,
                    pSrcSlice + pSrc->RowPitch * (LONG_PTR)y,
                    RowSizeInBytes);
        }
    }
}

inline uint64_t d3d12_updateSubresources_impl(ID3D12GraphicsCommandList* pCmdList,
    ID3D12Resource* pDestinationResource,
    ID3D12Resource* pIntermediate,
    UINT FirstResource,
    UINT NumSubresources,
    uint64_t RequiredSize,
    const D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    const UINT* pNumRows,
    const uint64_t* pRowSizeBytes,
    const D3D12_SUBRESOURCE_DATA* pSrcData
){

    D3D12_RESOURCE_DESC IntermediateDesc;
    pIntermediate->lpVtbl->GetDesc(pIntermediate,&IntermediateDesc);
    D3D12_RESOURCE_DESC DestinationDesc;
    pDestinationResource->lpVtbl->GetDesc(pDestinationResource,&DestinationDesc);

    if (IntermediateDesc.Dimension != D3D12_RESOURCE_DIMENSION_BUFFER ||
        IntermediateDesc.Width < RequiredSize + pLayouts[0].Offset ||
        RequiredSize > (SIZE_T)(-1) ||
        (DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER &&
            (FirstResource != 0 || NumSubresources != 1))
    ){
        return 0;
    }

    BYTE* pData;
    HRESULT hr  = pIntermediate->lpVtbl->Map(pIntermediate,0,NULL,(void**)&pData);
    if(FAILED(hr)){
        return 0;
    }

    for(UINT i = 0;i<NumSubresources;++i){
        if(pRowSizeBytes[i] > (SIZE_T)(-1)) return 0;
        D3D12_MEMCPY_DEST DestData = {pData + pLayouts[i].Offset, pLayouts[i].Footprint.RowPitch, (SIZE_T)pLayouts[i].Footprint.RowPitch * (SIZE_T)pNumRows[i]};
        d3d12_memcpySubresource(&DestData,&pSrcData[i], (SIZE_T)(pRowSizeBytes[i]),pNumRows[i],pLayouts[i].Footprint.Depth);
    }
    pIntermediate->lpVtbl->Unmap(pIntermediate,0,NULL);

    if(DestinationDesc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER){
        pCmdList->lpVtbl->CopyBufferRegion(pCmdList,pDestinationResource,0,pIntermediate,pLayouts[0].Offset,pLayouts[0].Footprint.Width);
    }
    else{
        for(UINT i =0;i<NumSubresources;++i){
            D3D12_TEXTURE_COPY_LOCATION Dst = {0};
            Dst.pResource = pDestinationResource;
            Dst.Type = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
            Dst.SubresourceIndex = i + FirstResource;

            D3D12_TEXTURE_COPY_LOCATION Src = {0};
            Src.pResource = pIntermediate;
            Src.Type = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
            Src.PlacedFootprint = pLayouts[i];

            pCmdList->lpVtbl->CopyTextureRegion(pCmdList,&Dst,0,0,0,&Src,NULL);
        }
    }
    return RequiredSize;
}
inline uint64_t d3d12_updateSubresources(ID3D12GraphicsCommandList* pCmdList,
    ID3D12Resource* pDestinationResource,
    ID3D12Resource* pIntermediate,
    uint64_t IntermediateOffset,
    unsigned int FirstSubresource,
    unsigned int NumSubresources, 
    const D3D12_SUBRESOURCE_DATA* pSrcData
){
    uint64_t required_size = 0;
    const uint64_t mem_to_alloc = (uint64_t)(sizeof(D3D12_PLACED_SUBRESOURCE_FOOTPRINT) + sizeof(unsigned int)+sizeof(uint64_t) * NumSubresources);
    if(mem_to_alloc>SIZE_MAX){
        return 0;
    }
    void* pMem = HeapAlloc(GetProcessHeap(),0,(size_t)mem_to_alloc);
    if(pMem == NULL){
        return 0;
    }
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts = (D3D12_PLACED_SUBRESOURCE_FOOTPRINT*)pMem;
    uint64_t* pRowSizesInBytes = (uint64_t*)(pLayouts+NumSubresources);
    unsigned int* pNumRows = (unsigned int*)(pRowSizesInBytes + NumSubresources);

    D3D12_RESOURCE_DESC temp_Desc; 
    pDestinationResource->lpVtbl->GetDesc(pDestinationResource,&temp_Desc);
    const D3D12_RESOURCE_DESC Desc = temp_Desc;
    ID3D12Device* pDevice = NULL;
    pDestinationResource->lpVtbl->GetDevice(pDestinationResource,&IID_ID3D12Device,(void**)&pDevice);
    pDevice->lpVtbl->GetCopyableFootprints(pDevice,&Desc,FirstSubresource,NumSubresources,IntermediateOffset,pLayouts,pNumRows,pRowSizesInBytes,&required_size);
    pDevice->lpVtbl->Release(pDevice);
    
    const uint64_t result = d3d12_updateSubresources_impl(pCmdList,pDestinationResource,pIntermediate,FirstSubresource,NumSubresources,required_size,pLayouts,pNumRows,pRowSizesInBytes,pSrcData);
    HeapFree(GetProcessHeap(),0,pMem);
    return result;
}

//DX12 OBJECT CREATION FUNCTIONS

static inline HRESULT _slg_d3d12_CreateDXGIFactory2(UINT Flags, IDXGIFactory2** ppFactory){
    #if defined(__cplusplus)
    //shit pant
    #else
    return CreateDXGIFactory2(Flags, &IID_IDXGIFactory2 ,(void**)ppFactory);
    #endif
}
static inline HRESULT _slg_d3d12_CreateDevice(IUnknown *pAdapter,D3D_FEATURE_LEVEL minimumFeatureLevel,ID3D12Device **ppDevice){
    return D3D12CreateDevice(pAdapter,minimumFeatureLevel,&IID_ID3D12Device,(void**)ppDevice);
}

void _slg_d3d12_GetHardwareAdapter(IDXGIFactory1* pFactory, IDXGIAdapter1** ppAdapter, bool requestHighPerformanceAdapter){
    IDXGIAdapter1* adapter = NULL;
    IDXGIFactory6* factory6 = NULL;
    if(SUCCEEDED(pFactory->lpVtbl->QueryInterface(pFactory,&IID_IDXGIFactory6,(void**)&factory6))){
        UINT adapterIndex = 0;
        while(true){
            if(factory6->lpVtbl->EnumAdapterByGpuPreference(factory6,
                adapterIndex,
                requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                &IID_IDXGIAdapter1,
                &adapter) == DXGI_ERROR_NOT_FOUND){
                    break;
            }
            DXGI_ADAPTER_DESC1 desc;
            adapter->lpVtbl->GetDesc1(adapter, &desc);

            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE){
                continue;
            }
            if(SUCCEEDED(D3D12CreateDevice((IUnknown*)adapter,D3D_FEATURE_LEVEL_11_0,&IID_ID3D12Device,NULL))){
                break;
            }
            adapterIndex++;
        }
    }
    factory6->lpVtbl->Release(factory6);

    if(adapter == NULL){
        for(UINT adapterIndex = 0;SUCCEEDED(pFactory->lpVtbl->EnumAdapters1(pFactory,adapterIndex,&adapter));adapterIndex++){
            DXGI_ADAPTER_DESC1 desc;
            adapter->lpVtbl->GetDesc1(adapter,&desc);
            if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE){
                continue;
            }
            if(SUCCEEDED(D3D12CreateDevice((IUnknown*)adapter,D3D_FEATURE_LEVEL_11_0,&IID_ID3D12Device,NULL))){
                break;
            }
        }
    }
    *ppAdapter = adapter;
}

void _slg_d3d12_CreateDeviceAndSwapChain(slg_desc_t *desc, slg_framebuffer_t *framebuffer,slg_fence_t *fence){
    UINT dxgiFactoryFlags = 0;

    {
        ID3D12Debug* debugController;
        if(SUCCEEDED(D3D12GetDebugInterface(&IID_ID3D12Debug,(void**)&debugController))){
            debugController->lpVtbl->EnableDebugLayer(debugController);
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }
    }

    IDXGIFactory4* factory = NULL;
    d3d12_throwIfFailed(_slg_d3d12_CreateDXGIFactory2(dxgiFactoryFlags,(IDXGIFactory2**)&factory));
    bool useWarpDevice = false;
    if(useWarpDevice){
        IDXGIAdapter* warpAdapter;
        d3d12_throwIfFailed(factory->lpVtbl->EnumWarpAdapter(factory,&IID_IDXGIAdapter,(void**)&warpAdapter));
        d3d12_throwIfFailed(_slg_d3d12_CreateDevice((IUnknown*)warpAdapter,D3D_FEATURE_LEVEL_11_0,&desc->device));
        warpAdapter->lpVtbl->Release(warpAdapter);
        warpAdapter = NULL;
    }
    else{
        IDXGIAdapter1* hardwareAdapter;
        _slg_d3d12_GetHardwareAdapter((IDXGIFactory1*)factory,&hardwareAdapter,true);
        d3d12_throwIfFailed(_slg_d3d12_CreateDevice((IUnknown*)hardwareAdapter,D3D_FEATURE_LEVEL_11_0,&desc->device));
        hardwareAdapter->lpVtbl->Release(hardwareAdapter);
        hardwareAdapter = NULL;
    }

    D3D12_COMMAND_QUEUE_DESC queueDesc = {0};
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    d3d12_throwIfFailed(desc->device->lpVtbl->CreateCommandQueue(desc->device,&queueDesc,&IID_ID3D12CommandQueue,(void**)&desc->commandQueue));

    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};
    swapChainDesc.BufferCount = FrameCount;
    swapChainDesc.Width = slg_d3d12_state.appdata.width;
    swapChainDesc.Height = slg_d3d12_state.appdata.height;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;

    IDXGISwapChain1* swapChain;
    d3d12_throwIfFailed(factory->lpVtbl->CreateSwapChainForHwnd(factory,
        (IUnknown*)desc->commandQueue,
        slg_d3d12_state.appdata.hwnd,
        &swapChainDesc,
        NULL,
        NULL,
        &swapChain 
    ));

    d3d12_throwIfFailed(swapChain->lpVtbl->QueryInterface(swapChain,&IID_IDXGISwapChain3,(void**)&framebuffer->swapchain));
    swapChain->lpVtbl->Release(swapChain);

    d3d12_throwIfFailed(factory->lpVtbl->MakeWindowAssociation(factory,slg_d3d12_state.appdata.hwnd,DXGI_MWA_NO_ALT_ENTER));

    framebuffer->frameIndex = framebuffer->swapchain->lpVtbl->GetCurrentBackBufferIndex(framebuffer->swapchain);

    factory->lpVtbl->Release(factory);
    factory = NULL;
}


void _slg_d3d12_CreateRenderTarget(slg_desc_t desc,slg_framebuffer_t *framebuffer){
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {0};
    rtvHeapDesc.NumDescriptors = FrameCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    d3d12_throwIfFailed(desc.device->lpVtbl->CreateDescriptorHeap(desc.device,&rtvHeapDesc,&IID_ID3D12DescriptorHeap,(void**)&framebuffer->rtvHeap));
    
    framebuffer->rtvDescriptorSize = desc.device->lpVtbl->GetDescriptorHandleIncrementSize(desc.device,D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}

void _slg_d3d12_CreateRTVHandle(slg_desc_t desc, slg_framebuffer_t *framebuffer){
    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = {0};
    framebuffer->rtvHeap->lpVtbl->GetCPUDescriptorHandleForHeapStart(framebuffer->rtvHeap,&rtvHandle);
    for(UINT n = 0;n<FrameCount;n++){
        d3d12_throwIfFailed(framebuffer->swapchain->lpVtbl->GetBuffer(framebuffer->swapchain,n,&IID_ID3D12Resource,(void**)&framebuffer->frame_context[n].renderTarget));
        desc.device->lpVtbl->CreateRenderTargetView(desc.device,framebuffer->frame_context[n].renderTarget,NULL,rtvHandle);
        framebuffer->frame_context[n].rtvHandle = rtvHandle;
        rtvHandle.ptr += framebuffer->rtvDescriptorSize;
    }
}

void _slg_d3d12_CreateCommandAllocator(ID3D12Device* device, ID3D12CommandAllocator** command_allocator){
    d3d12_throwIfFailed(device->lpVtbl->CreateCommandAllocator(device,D3D12_COMMAND_LIST_TYPE_DIRECT,&IID_ID3D12CommandAllocator,(void**)command_allocator));
}


void _slg_d3d12_CreateCommandList(ID3D12Device* device,ID3D12CommandAllocator* command_allocator,ID3D12GraphicsCommandList** command_list){
    d3d12_throwIfFailed(device->lpVtbl->CreateCommandList(device,0,D3D12_COMMAND_LIST_TYPE_DIRECT,command_allocator,NULL,&IID_ID3D12CommandList,(void**)command_list));
    d3d12_throwIfFailed((*command_list)->lpVtbl->Close(*command_list));
    d3d12_throwIfFailed((*command_list)->lpVtbl->Reset(*command_list,command_allocator,NULL));
}


void _slg_d3d12_CreateDepthBuffer(slg_desc_t* desc, slg_app_data_t* appdata,slg_framebuffer_t* frame_buf){
    D3D12_RESOURCE_DESC depthDesc = {0};
    depthDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    depthDesc.Width = appdata->width;
    depthDesc.Height = appdata->height;
    depthDesc.MipLevels = 1;
    depthDesc.DepthOrArraySize = 1;
    depthDesc.Format = DXGI_FORMAT_D32_FLOAT;
    depthDesc.SampleDesc.Count = 1;
    depthDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

    D3D12_CLEAR_VALUE depthClearValue = {0};
    depthClearValue.Format = DXGI_FORMAT_D32_FLOAT;
    depthClearValue.DepthStencil.Depth = 1.0f;
    depthClearValue.DepthStencil.Stencil = 0;
    
    
    D3D12_HEAP_PROPERTIES heapProps = { D3D12_HEAP_TYPE_DEFAULT };
    
    D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {0};
    dsvHeapDesc.NumDescriptors = FrameCount;
    dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    desc->device->lpVtbl->CreateDescriptorHeap(desc->device,&dsvHeapDesc,&IID_ID3D12DescriptorHeap,(void**)&frame_buf->depthStencilHeap);
    frame_buf->depthStencilDescriptorSize = desc->device->lpVtbl->GetDescriptorHandleIncrementSize(desc->device, D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
    D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = {0};
    frame_buf->depthStencilHeap->lpVtbl->GetCPUDescriptorHandleForHeapStart(frame_buf->depthStencilHeap,&dsvHandle);
    for(int i = 0;i< FrameCount;i++){
        frame_buf->frame_context[i].depthTarget = NULL;
        desc->device->lpVtbl->CreateCommittedResource(desc->device,
            &heapProps,
            D3D12_HEAP_FLAG_NONE,
            &depthDesc,
            D3D12_RESOURCE_STATE_DEPTH_WRITE,
            &depthClearValue,
            &IID_ID3D12Resource,
            (void**)&frame_buf->frame_context[i].depthTarget
        );
        D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {0};
        dsvDesc.Format = DXGI_FORMAT_D32_FLOAT;
        dsvDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
        dsvDesc.Flags = D3D12_DSV_FLAG_NONE;

        
        
        desc->device->lpVtbl->CreateDepthStencilView(desc->device,frame_buf->frame_context[i].depthTarget,&dsvDesc,dsvHandle);
        frame_buf->frame_context[i].depthHandle = dsvHandle;
        dsvHandle.ptr += frame_buf->depthStencilDescriptorSize;    
    }

}

void _slg_d3d12_CreateFence(){
    slg_desc_t *desc = &slg_d3d12_state.desc;
    slg_fence_t *fence = &slg_d3d12_state.fence;

    slg_frame_context_t* frame_context = &slg_d3d12_state.frame_buf.frame_context[slg_d3d12_state.frame_buf.frameIndex];
    d3d12_throwIfFailed(desc->device->lpVtbl->CreateFence(desc->device,frame_context->fenceValue,D3D12_FENCE_FLAG_NONE,&IID_ID3D12Fence,(void**)&fence->fence));
    //frame_context->fenceValue++;

    fence->fenceEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
    if(fence->fenceEvent == NULL){
        d3d12_throwIfFailed(HRESULT_FROM_WIN32(GetLastError()));
    }
}

//SLUGS FUNCTIONS FOR DX12 IMPLEMENTATION 
static inline slg_shader _slg_d3d12_make_shader(slg_shader_desc* shader_desc){
    
    SLG_ASSERT(shader_desc->filename!=NULL);


    slg_shader shd = {0};

    shd.shader_ptr = pool_alloc(&slg_pools.shader_pool);
    if(shd.shader_ptr == NULL){
        SLG_ASSERT(false && "out of room to allocate");
    }
    WCHAR vert_shader_name[MAX_PATH]; 
    d3d12_GetAssetFullPath(shader_desc->vert_shader_name,vert_shader_name);
    WCHAR frag_shader_name[MAX_PATH]; 
    d3d12_GetAssetFullPath(shader_desc->frag_shader_name,frag_shader_name);

    /*slg_shader_source_data* file_data = pool_alloc(&slg_pools.shaderFileReferencePool);
    file_data->shader_ptr = shd.shader_ptr;
    strncpy(file_data->vert_shader_cso,shader_desc->vert_shader_name,sizeof(file_data->vert_shader_cso));
    strncpy(file_data->frag_shader_cso,shader_desc->vert_shader_name,sizeof(file_data->frag_shader_cso));
    strncpy(file_data->hlsl_name,shader_desc->filename,sizeof(file_data->hlsl_name));*/

    strncpy(shd.shader_ptr->vert_shader_cso,shader_desc->vert_shader_name,sizeof(shd.shader_ptr->vert_shader_cso));
    strncpy(shd.shader_ptr->frag_shader_cso,shader_desc->frag_shader_name,sizeof(shd.shader_ptr->frag_shader_cso));
    strncpy(shd.shader_ptr->hlsl_name,shader_desc->filename,sizeof(shd.shader_ptr->hlsl_name));
    
    
    d3d12_throwIfFailed(D3DReadFileToBlob(vert_shader_name, &shd.shader_ptr->VertexShaderBlob));
    d3d12_throwIfFailed(D3DReadFileToBlob(frag_shader_name, &shd.shader_ptr->PixelShaderBlob));

/*
#if defined(_Debug)
    UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
    UINT compileFlags = 0;
#endif
    slg_shader shd = {0};

    shd.shader_ptr = pool_alloc(&slg_pools.shader_pool);
    if(shd.shader_ptr == NULL){
        SLG_ASSERT(false && "out of room to allocate");
    }
    ID3DBlob* errorBlob = NULL;
    d3d12_throwIfFailed_Error(D3DCompileFromFile(d3d12_filepath,
        NULL,
        NULL,
        shader_desc->vert_shader_name,
        (shader_desc->vert_shader_target != NULL) ? shader_desc->vert_shader_target : "vs_5_0",
        compileFlags,
        0,
        &shd.shader_ptr->VertexShaderBlob,&errorBlob
    ),
        errorBlob);
    ID3D12ShaderReflection* vs_reflection = NULL;

    d3d12_throwIfFailed(D3DReflect(shd.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferPointer(shd.shader_ptr->VertexShaderBlob),
        shd.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferSize(shd.shader_ptr->VertexShaderBlob),
        &IID_ID3D12ShaderReflection,
        (void**)&vs_reflection
    ));
    
    D3D12_SHADER_DESC vs_shader_reflection_desc = {0};
    vs_reflection->lpVtbl->GetDesc(vs_reflection,&vs_shader_reflection_desc);
   
    for(unsigned int i = 0;i<vs_shader_reflection_desc.BoundResources;i++){
        D3D12_SHADER_INPUT_BIND_DESC bind_desc = {0};    
        vs_reflection->lpVtbl->GetResourceBindingDesc(vs_reflection,i,&bind_desc);

    }

    d3d12_throwIfFailed(D3DCompileFromFile(d3d12_filepath,
        NULL,
        NULL,
        shader_desc->frag_shader_name,
        (shader_desc->frag_shader_target != NULL) ? shader_desc->frag_shader_target : "ps_5_0",
        compileFlags,
        0,
        &shd.shader_ptr->PixelShaderBlob,
        NULL    
    ));

    ID3D12ShaderReflection* ps_reflection = NULL;
    d3d12_throwIfFailed(D3DReflect(shd.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferPointer(shd.shader_ptr->PixelShaderBlob),
        shd.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferSize(shd.shader_ptr->PixelShaderBlob),
        &IID_ID3D12ShaderReflection,
        (void**)&ps_reflection
    ));
    D3D12_SHADER_DESC ps_shader_reflection_desc = {0};
    

    ps_reflection->lpVtbl->GetDesc(ps_reflection,&ps_shader_reflection_desc);

    for(unsigned int i = 0;i<ps_shader_reflection_desc.BoundResources;i++){
        D3D12_SHADER_INPUT_BIND_DESC bind_desc = {0};    
        vs_reflection->lpVtbl->GetResourceBindingDesc(ps_reflection,i,&bind_desc);
    }

    if(vs_reflection){
        vs_reflection->lpVtbl->Release(vs_reflection);
    }
    if(ps_reflection){
        ps_reflection->lpVtbl->Release(ps_reflection);
    }
  */  
    return shd;
}
static inline slg_texture _slg_d3d12_make_texture(slg_texture_desc* texture_desc){
    slg_desc_t desc = slg_d3d12_state.desc;
    slg_framebuffer_t frame_buf = slg_d3d12_state.frame_buf;
    slg_texture tex = {0};
    tex.data_ptr = pool_alloc(&slg_pools.texture_pool);
    D3D12_HEAP_PROPERTIES heap_props;
    heap_props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heap_props.Type = D3D12_HEAP_TYPE_DEFAULT;
    heap_props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    heap_props.CreationNodeMask = 1;
    heap_props.VisibleNodeMask = 1;

    int num_faces = _slg_getArrraySizeFromTexType(texture_desc->tex_type);
    D3D12_RESOURCE_DESC resource_desc;
    resource_desc.Dimension = _slg_d3d12_convert_resource_dimension(texture_desc->tex_type);
    resource_desc.Alignment = 0;
    resource_desc.Width = texture_desc->width;
    resource_desc.Height = texture_desc->height;
    resource_desc.DepthOrArraySize = (uint16_t)num_faces;
    resource_desc.MipLevels = 1;
    resource_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    resource_desc.SampleDesc.Count = 1;
    resource_desc.SampleDesc.Quality = 0;
    resource_desc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    resource_desc.Flags = D3D12_RESOURCE_FLAG_NONE;

    d3d12_throwIfFailed(desc.device->lpVtbl->CreateCommittedResource(desc.device,
        &heap_props,
        D3D12_HEAP_FLAG_NONE,
        &resource_desc,
        D3D12_RESOURCE_STATE_COPY_DEST,
        NULL,
        &IID_ID3D12Resource,
        (void**)&tex.data_ptr->texture   
    ));
    
    D3D12_RESOURCE_DESC write_desc = {0};
    tex.data_ptr->texture->lpVtbl->GetDesc(tex.data_ptr->texture,&write_desc);
    uint64_t required_size = 0;
    //UINT64 RequiredSize = 0;

    ID3D12Device* pDevice = NULL;
    tex.data_ptr->texture->lpVtbl->GetDevice(tex.data_ptr->texture,&IID_ID3D12Device,(void**)&pDevice);
    //pDestinationResource->GetDevice(IID_ID3D12Device, reinterpret_cast<void**>(&pDevice));
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT layouts[6];
   
    pDevice->lpVtbl->GetCopyableFootprints(pDevice,
        &write_desc,
        0,
        num_faces,
        0,
        layouts,
        NULL,
        NULL,
        &required_size
    );
    
    pDevice->lpVtbl->Release(pDevice);
    const uint64_t uploadBufferSize = required_size;

    ID3D12Resource* textureUploadHeap = NULL;
    //now that we have the size we can create the gpu upload buffer
    D3D12_HEAP_PROPERTIES upload_heap_props = {0};
    upload_heap_props.Type = D3D12_HEAP_TYPE_UPLOAD;
    upload_heap_props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    upload_heap_props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    upload_heap_props.CreationNodeMask = 1;
    upload_heap_props.VisibleNodeMask = 1;

    D3D12_RESOURCE_DESC upload_buffer_desc={0};
    upload_buffer_desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    upload_buffer_desc.Alignment = 0;
    upload_buffer_desc.Width = uploadBufferSize;
    upload_buffer_desc.Height = 1;
    upload_buffer_desc.DepthOrArraySize = 1;
    upload_buffer_desc.MipLevels = 1;
    upload_buffer_desc.Format = DXGI_FORMAT_UNKNOWN;
    upload_buffer_desc.SampleDesc.Count = 1;
    upload_buffer_desc.SampleDesc.Quality = 0;
    upload_buffer_desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    upload_buffer_desc.Flags = D3D12_RESOURCE_FLAG_NONE;

    d3d12_throwIfFailed(desc.device->lpVtbl->CreateCommittedResource(desc.device,
        &upload_heap_props,
        D3D12_HEAP_FLAG_NONE,
        &upload_buffer_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        NULL,
        &IID_ID3D12Resource,
        (void**)&textureUploadHeap
    ));
    
    ID3D12GraphicsCommandList* command_list = frame_buf.frame_context[frame_buf.frameIndex].commandList; 
    for(int i = 0;i < (uint16_t)num_faces;i++){
        D3D12_SUBRESOURCE_DATA texture_data = {0};
        texture_data.pData = (unsigned char*)texture_desc->texture + (texture_desc->width*texture_desc->height*texture_desc->pixel_size*i);
        texture_data.RowPitch  = texture_desc->width * texture_desc->pixel_size;
        texture_data.SlicePitch = texture_data.RowPitch * texture_desc->height;
        
        d3d12_updateSubresources(command_list,tex.data_ptr->texture,textureUploadHeap,layouts[i].Offset,i,1,&texture_data);
    }
    /*D3D12_SUBRESOURCE_DATA texture_data = {0};
    texture_data.pData = texture_desc->texture;
    texture_data.RowPitch  = texture_desc->width * texture_desc->pixel_size;
    texture_data.SlicePitch = texture_data.RowPitch * texture_desc->height;

    d3d12_updateSubresources(desc.commandList,tex.data_ptr->texture,textureUploadHeap,0,0,1,&texture_data);
    */
    D3D12_RESOURCE_BARRIER barrier;
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier.Transition.pResource = tex.data_ptr->texture;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_DEST;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
    command_list->lpVtbl->ResourceBarrier(command_list,1,&barrier);
    
    return tex;
    
} 
static inline slg_pipeline _slg_d3d12_make_pipeline(slg_pipeline_desc* pipeline_desc){
    //ds_pipeline_desc valid_desc = 
    //unsigned char* backingBuffer[65536];
    //pool_init(&ds_pipeline_pool,backingBuffer,65536,sizeof(ds_shader_t),16);

    
    slg_desc_t desc = slg_d3d12_state.desc;
    slg_pipeline pip = {0}; 
    pip.data_ptr = pool_alloc(&slg_pools.pipeline_pool);
    
    slg_default_pipeline_desc(pipeline_desc);
    #ifdef SLG_HOT_RELOADING
        pip.data_ptr->shader_ptr = pipeline_desc->shader.shader_ptr;
    #endif
    

    //lets use the shader reflection data to build the root_parameters here
    ID3D12ShaderReflection* vs_reflection = NULL;

    d3d12_throwIfFailed(D3DReflect(pipeline_desc->shader.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferPointer(pipeline_desc->shader.shader_ptr->VertexShaderBlob),
        pipeline_desc->shader.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferSize(pipeline_desc->shader.shader_ptr->VertexShaderBlob),
        &IID_ID3D12ShaderReflection,
        (void**)&vs_reflection
    ));
    D3D12_SHADER_DESC vs_shader_reflection_desc = {0};
    vs_reflection->lpVtbl->GetDesc(vs_reflection,&vs_shader_reflection_desc);

    D3D12_INPUT_ELEMENT_DESC input_elements[SLG_D3D12_MAXIMUM_INPUT_LIMIT] = {0};
    unsigned int num_input_elements = vs_shader_reflection_desc.InputParameters;
    /*
    NOTE: when adding instancing the the input slot class and instanceDataStepRate will need to be changed
    */

    //i need some sort of manual override for the input parameter description maybe

    //i could pass in a pointer of formats, as well size. Then I could check if it's null, and if it's not then assign it manually
    D3D12_SIGNATURE_PARAMETER_DESC input_parameter_desc[SLG_D3D12_MAXIMUM_INPUT_LIMIT];
    for(unsigned int i = 0;i<num_input_elements;i++){
        
        d3d12_throwIfFailed(vs_reflection->lpVtbl->GetInputParameterDesc(vs_reflection,i,&input_parameter_desc[i]));
        memcpy(pip.data_ptr->sematic_names[i],input_parameter_desc[i].SemanticName,sizeof(input_parameter_desc[i].SemanticName));
        input_elements[i].SemanticName = pip.data_ptr->sematic_names[i];
        input_elements[i].SemanticIndex = input_parameter_desc[i].SemanticIndex;
        if(pipeline_desc->num_overrides>0){
            input_elements[i].Format = pipeline_desc->format_overrides[i];
        }
        else{
            input_elements[i].Format = _slg_d3d12_D3DCOMPONENTTYPE_to_DXGIFORMAT(input_parameter_desc[i].ComponentType,input_parameter_desc[i].ReadWriteMask);
        }
        //input_elements[i].Format = _slg_d3d12_D3DCOMPONENTTYPE_to_DXGIFORMAT(input_parameter_desc[i].ComponentType,input_parameter_desc[i].ReadWriteMask);
        input_elements[i].InputSlot = 0;
        input_elements[i].AlignedByteOffset = D3D12_APPEND_ALIGNED_ELEMENT;
        input_elements[i].InputSlotClass = D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA;
        input_elements[i].InstanceDataStepRate = 0;
    }
    
    
    ID3D12ShaderReflection* ps_reflection = NULL;

    d3d12_throwIfFailed(D3DReflect(pipeline_desc->shader.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferPointer(pipeline_desc->shader.shader_ptr->PixelShaderBlob),
        pipeline_desc->shader.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferSize(pipeline_desc->shader.shader_ptr->PixelShaderBlob),
        &IID_ID3D12ShaderReflection,
        (void**)&ps_reflection
    ));

    D3D12_SHADER_DESC ps_shader_reflection_desc = {0};
    ps_reflection->lpVtbl->GetDesc(ps_reflection,&ps_shader_reflection_desc);
    D3D12_DESCRIPTOR_RANGE CBV_range = {0};
    D3D12_DESCRIPTOR_RANGE SRV_range = {0};
    D3D12_DESCRIPTOR_RANGE UAV_range = {0};
    D3D12_DESCRIPTOR_RANGE SAMPLER_range = {0};
    unsigned int cbv_descriptor_count = 0;
    unsigned int srv_descriptor_count = 0;
    unsigned int uav_descriptor_count = 0;
    unsigned int sampler_descriptor_count = 0;
    
    
    for(unsigned int i = 0;i < vs_shader_reflection_desc.BoundResources;i++){
        D3D12_SHADER_INPUT_BIND_DESC bind_desc = {0};
        vs_reflection->lpVtbl->GetResourceBindingDesc(vs_reflection,i,&bind_desc);
        if(bind_desc.Type == D3D_SIT_CBUFFER){
            if(cbv_descriptor_count == 0){
                CBV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
                CBV_range.BaseShaderRegister = bind_desc.BindPoint;
                CBV_range.RegisterSpace = bind_desc.Space;
                CBV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
            
            CBV_range.NumDescriptors = cbv_descriptor_count;
            cbv_descriptor_count += bind_desc.BindCount;
            
        }
        else if(bind_desc.Type == D3D_SIT_TEXTURE){
            if(srv_descriptor_count == 0){
                SRV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
                SRV_range.BaseShaderRegister = bind_desc.BindPoint;
                SRV_range.RegisterSpace = bind_desc.Space;
                SRV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
           
            srv_descriptor_count += bind_desc.BindCount;
            SRV_range.NumDescriptors = srv_descriptor_count;
            
            
        }
        else if(bind_desc.Type == D3D_SIT_UAV_RWTYPED || bind_desc.Type == D3D_SIT_UAV_RWSTRUCTURED || bind_desc.Type == D3D_SIT_UAV_RWBYTEADDRESS){
            if(uav_descriptor_count == 0)
            {
                UAV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
                UAV_range.BaseShaderRegister = bind_desc.BindPoint;
                UAV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
                UAV_range.RegisterSpace = bind_desc.Space;
            }
            
            uav_descriptor_count += bind_desc.BindCount;
            UAV_range.NumDescriptors = uav_descriptor_count;
            
        }
        else if(bind_desc.Type == D3D_SIT_SAMPLER){
            if(sampler_descriptor_count == 0){
                SAMPLER_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
                SAMPLER_range.BaseShaderRegister = bind_desc.BindPoint;
                SAMPLER_range.RegisterSpace = bind_desc.Space;
                SAMPLER_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
            sampler_descriptor_count += bind_desc.BindCount;
            SAMPLER_range.NumDescriptors = sampler_descriptor_count;

        }
        
    }
    for(unsigned int i = 0; i<ps_shader_reflection_desc.BoundResources;i++){
        D3D12_SHADER_INPUT_BIND_DESC bind_desc = {0};
        ps_reflection->lpVtbl->GetResourceBindingDesc(ps_reflection,i,&bind_desc);
        if(bind_desc.Type == D3D_SIT_CBUFFER){
            if(cbv_descriptor_count == 0){
                CBV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
                CBV_range.BaseShaderRegister = bind_desc.BindPoint;
                CBV_range.RegisterSpace = bind_desc.Space;
                CBV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
            
            CBV_range.NumDescriptors = cbv_descriptor_count;
            cbv_descriptor_count += bind_desc.BindCount;
            
        }
        else if(bind_desc.Type == D3D_SIT_TEXTURE){
            if(srv_descriptor_count == 0){
                SRV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
                SRV_range.BaseShaderRegister = bind_desc.BindPoint;
                SRV_range.RegisterSpace = bind_desc.Space;
                SRV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
            srv_descriptor_count += bind_desc.BindCount;
            SRV_range.NumDescriptors = srv_descriptor_count;
        }
        else if(bind_desc.Type == D3D_SIT_UAV_RWTYPED || bind_desc.Type == D3D_SIT_UAV_RWSTRUCTURED || bind_desc.Type == D3D_SIT_UAV_RWBYTEADDRESS){
            if(uav_descriptor_count == 0)
            {
                UAV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
                UAV_range.BaseShaderRegister = bind_desc.BindPoint;
                UAV_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
                UAV_range.RegisterSpace = bind_desc.Space;
            }
            uav_descriptor_count += bind_desc.BindCount;
            UAV_range.NumDescriptors = uav_descriptor_count;
            
        }
        else if(bind_desc.Type == D3D_SIT_SAMPLER){
            if(sampler_descriptor_count == 0){
                SAMPLER_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
                SAMPLER_range.BaseShaderRegister = bind_desc.BindPoint;
                SAMPLER_range.RegisterSpace = bind_desc.Space;
                SAMPLER_range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
            }
            sampler_descriptor_count += bind_desc.BindCount;
            SAMPLER_range.NumDescriptors = sampler_descriptor_count;
        }

    }

    if(CBV_range.NumDescriptors == 0){
        CBV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
        CBV_range.NumDescriptors = 1;
    } 
    if(SRV_range.NumDescriptors == 0){
        SRV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
        SRV_range.NumDescriptors = 1;
    } 
    if(UAV_range.NumDescriptors == 0){
        UAV_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
        UAV_range.NumDescriptors = 1;
    } 
    if(SAMPLER_range.NumDescriptors == 0){
        SAMPLER_range.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
        SAMPLER_range.NumDescriptors = 1;
    } 
    //can we check the type of desciptor ranges that have been included
    D3D12_ROOT_PARAMETER rootParameters[4];
    rootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParameters[0].DescriptorTable.NumDescriptorRanges = 1;
    rootParameters[0].DescriptorTable.pDescriptorRanges = &CBV_range;
    rootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
    
    rootParameters[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParameters[1].DescriptorTable.NumDescriptorRanges = 1;
    rootParameters[1].DescriptorTable.pDescriptorRanges = &SRV_range;
    rootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParameters[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParameters[2].DescriptorTable.NumDescriptorRanges = 1;
    rootParameters[2].DescriptorTable.pDescriptorRanges = &UAV_range;
    rootParameters[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    rootParameters[3].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    rootParameters[3].DescriptorTable.NumDescriptorRanges = 1;
    rootParameters[3].DescriptorTable.pDescriptorRanges = &SAMPLER_range;
    rootParameters[3].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;

    
    

    D3D12_STATIC_SAMPLER_DESC sampler = {0};
        sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
        sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
        sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
        sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
        sampler.MipLODBias = 0;
        sampler.MaxAnisotropy = 0;
        sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
        sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
        sampler.MinLOD = 0.0f;
        sampler.MaxLOD = D3D12_FLOAT32_MAX;
        sampler.ShaderRegister = 0;
        sampler.RegisterSpace = 0;
        sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
    
    //D3D12_DESCRIPTOR_RANGE range = {0};
    //range.RangeType = _ds_d3d12_convert_descriptor_range_type(DS_DESCRIPTOR_RANGE_TYPE_CBV);
    //range.NumDescriptors = 1;
    //range.BaseShaderRegister = 0;
    //range.RegisterSpace = 0;
    //range.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

    
    //rootParameters[0].ParameterType = _ds_d3d12_convert_root_parameter_type(DS_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE);
    //rootParameters[0].DescriptorTable.NumDescriptorRanges = 1;
    //rootParameters[0].DescriptorTable.pDescriptorRanges = &range;
    //rootParameters[0].ShaderVisibility = _ds_d3d12_convert_shader_visibility(DS_SHADER_VISIBILITY_ALL);

    D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {0};
    
    rootSignatureDesc.NumParameters = 4;
    rootSignatureDesc.pParameters = rootParameters;
    rootSignatureDesc.NumStaticSamplers = 0;
    rootSignatureDesc.pStaticSamplers = NULL;
    rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
    //--------------------------------------------------------------------------------------------------
    
    

    ID3DBlob* signature;
    ID3DBlob* error= NULL;
    d3d12_throwIfFailed_Error(D3D12SerializeRootSignature(&rootSignatureDesc,D3D_ROOT_SIGNATURE_VERSION_1,&signature,&error),error);
    d3d12_throwIfFailed(desc.device->lpVtbl->CreateRootSignature(desc.device,
        0,
        signature->lpVtbl->GetBufferPointer(signature),
        signature->lpVtbl->GetBufferSize(signature),
        &IID_ID3D12RootSignature,
        (void**)&pip.data_ptr->root_signature
    ));
    
    //we can release these after they are used
   

    //LOL THESE NEXT LINES ARE GONNA BE REAL UGLY
    D3D12_SHADER_BYTECODE vertexShader = {0};
    vertexShader.pShaderBytecode = pipeline_desc->shader.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferPointer(pipeline_desc->shader.shader_ptr->VertexShaderBlob); 
    vertexShader.BytecodeLength = pipeline_desc->shader.shader_ptr->VertexShaderBlob->lpVtbl->GetBufferSize(pipeline_desc->shader.shader_ptr->VertexShaderBlob);

    D3D12_SHADER_BYTECODE pixelShader = {0};
    pixelShader.pShaderBytecode = pipeline_desc->shader.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferPointer(pipeline_desc->shader.shader_ptr->PixelShaderBlob);
    pixelShader.BytecodeLength = pipeline_desc->shader.shader_ptr->PixelShaderBlob->lpVtbl->GetBufferSize(pipeline_desc->shader.shader_ptr->PixelShaderBlob);
    D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {0};


    /*D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = { //defining vertex layout
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0},
        {"COLOR",0,DXGI_FORMAT_R32G32B32_FLOAT,0,12,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0}
    };*/

    psoDesc.InputLayout.pInputElementDescs = input_elements;
    psoDesc.InputLayout.NumElements = num_input_elements;

    //psoDesc.InputLayout.pInputElementDescs = pipeline_desc->input_elements;
    //psoDesc.InputLayout.NumElements = pipeline_desc->num_input_elements;


    psoDesc.pRootSignature = pip.data_ptr->root_signature;
    psoDesc.VS = vertexShader;
    psoDesc.PS = pixelShader;
    
    D3D12_RASTERIZER_DESC rs = {
    _slg_d3d12_convert_fill_mode(pipeline_desc->rasterizer_desc.fill_mode),                  // FillMode
    _slg_d3d12_convert_cull_mode(pipeline_desc->rasterizer_desc.cull_mode),                   // CullMode
    _slg_d3d12_convert_facewinding(pipeline_desc->rasterizer_desc.facewinding_mode),                                  // FrontCounterClockwise
    pipeline_desc->rasterizer_desc.depth_bias,               // DepthBias
    pipeline_desc->rasterizer_desc.depth_bias_clamp,         // DepthBiasClamp
    pipeline_desc->rasterizer_desc.slope_scaled_depth_bias,  // SlopeScaledDepthBias
    true,                                   // DepthClipEnable  //THIS SHOULD KINDA JUST ALWAYS BE ENABLED
    pipeline_desc->rasterizer_desc.multisample_enable,                                  // MultisampleEnable
    pipeline_desc->rasterizer_desc.antialiased_line_enable,                                  // AntialiasedLineEnable
    pipeline_desc->rasterizer_desc.forced_sample_count,                                      // ForcedSampleCount
    _slg_d3d12_convert_conservative_rasterization_mode(pipeline_desc->rasterizer_desc.conservative_rasterization_mode) // ConservativeRaster
    };
    psoDesc.RasterizerState = rs;

    D3D12_BLEND_DESC bs;
    bs.AlphaToCoverageEnable = pipeline_desc->blend_desc.alpha_to_coverage_enable;
    bs.IndependentBlendEnable = pipeline_desc->blend_desc.independent_blend_enable;
    for (int i = 0; i < D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT; i++) {
        bs.RenderTarget[i].BlendEnable = pipeline_desc->blend_desc.blend_enable;
        bs.RenderTarget[i].LogicOpEnable = pipeline_desc->blend_desc.logic_op_enable;
        bs.RenderTarget[i].SrcBlend = _slg_d3d12_convert_blend_mode(pipeline_desc->blend_desc.src_blend);
        bs.RenderTarget[i].DestBlend = _slg_d3d12_convert_blend_mode(pipeline_desc->blend_desc.dest_blend);
        bs.RenderTarget[i].BlendOp = _slg_d3d12_convert_blend_op(pipeline_desc->blend_desc.blend_op);
        bs.RenderTarget[i].SrcBlendAlpha = _slg_d3d12_convert_blend_mode(pipeline_desc->blend_desc.src_blend_alpha);
        bs.RenderTarget[i].DestBlendAlpha = _slg_d3d12_convert_blend_mode(pipeline_desc->blend_desc.dest_blend_alpha);
        bs.RenderTarget[i].BlendOpAlpha = _slg_d3d12_convert_blend_op(pipeline_desc->blend_desc.blend_op_alpha);
        bs.RenderTarget[i].LogicOp = _slg_d3d12_convert_logic_op(pipeline_desc->blend_desc.logic_op);
        bs.RenderTarget[i].RenderTargetWriteMask = _slg_d3d12_convert_color_write_enable(pipeline_desc->blend_desc.color_write_enable);
    }
    psoDesc.BlendState = bs;

    //ONCE I ARRIVE AT A POINT WHERE I NEED THE DEPTH STENCIL THEN WE WILL FILL THIS OUT
    psoDesc.DepthStencilState.DepthEnable = pipeline_desc->depth_stencil_desc.depth_enable; 
    psoDesc.DepthStencilState.StencilEnable = pipeline_desc->depth_stencil_desc.stencil_enable; 
    psoDesc.DepthStencilState.DepthFunc = _slg_d3d12_convert_comparison_func(pipeline_desc->depth_stencil_desc.compare_func);
    psoDesc.DepthStencilState.DepthWriteMask = _slg_d3d12_convert_depth_write_mask(pipeline_desc->depth_stencil_desc.write_mask);
    psoDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;
    
    psoDesc.SampleMask = pipeline_desc->sample_mask;
    
    psoDesc.PrimitiveTopologyType = _slg_d3d12_convert_primitive_topology_type(pipeline_desc->primitive_topology_type);
    //psoDesc.NumRenderTargets = pipeline_desc.num_render_targets;
    psoDesc.NumRenderTargets = pipeline_desc->num_render_targets;

    for(unsigned int i = 0;i<pipeline_desc->num_render_targets;i++){
        psoDesc.RTVFormats[i] = DXGI_FORMAT_R8G8B8A8_UNORM;
    }

    //psoDesc.SampleDesc.Count = pipeline_desc.sample_desc.Count;
    psoDesc.SampleDesc.Count = pipeline_desc->sample_count;
    d3d12_throwIfFailed(desc.device->lpVtbl->CreateGraphicsPipelineState(desc.device,&psoDesc,&IID_ID3D12PipelineState,(void**)&pip.data_ptr->pipeline_state));
    vs_reflection->lpVtbl->Release(vs_reflection);
    ps_reflection->lpVtbl->Release(ps_reflection);
    /*
    pipeline_desc->shader.shader_ptr->PixelShaderBlob->lpVtbl->Release(pipeline_desc->shader.shader_ptr->PixelShaderBlob);
    pipeline_desc->shader.shader_ptr->VertexShaderBlob->lpVtbl->Release(pipeline_desc->shader.shader_ptr->VertexShaderBlob);
    pool_free(&slg_pools.shader_pool,pipeline_desc->shader.shader_ptr);
    */
    #ifdef SLG_HOT_RELOADING
        pip.data_ptr->pso_state_desc = psoDesc;
        memcpy(pip.data_ptr->input_element_descs,input_elements,sizeof(D3D12_INPUT_ELEMENT_DESC)*num_input_elements);//copy over the input elements for hot reloading
        pip.data_ptr->num_input_elements = num_input_elements;

    #endif
    return pip;
    
//
}

//Need to have shader reflection or something for proper bindings
//we could either pass it in, or have the header maybe idk?
static inline slg_bindings _slg_d3d12_make_bindings(slg_bindings_desc* bind_data){

    //we need to get reflection data in here somehow
    slg_desc_t desc = slg_d3d12_state.desc;
    slg_bindings bind = {0};
    bind.data_ptr = pool_alloc(&slg_pools.binding_pool);
    bind.data_ptr->vertex_buffer = bind_data->vertex_buffer;
    bind.data_ptr->index_buffer = bind_data->index_buffer;
    
    //might want to assign some sort of index assignment in the buffer maybe that maps
    //to the slot that this data goes in but for now I should just be smart about the data I pass in
    //this is a good dumb solution
    //bind.data_ptr->cbv_heap = bind_data.cbv_heap;
    //unsigned int max_csv_buffers = _countof(bind_data->resource_buffer) + _countof(bind_data->resource_buffer);
    //unsigned int num_csv_buffers = 0;
    //unsigned int num_samplers = _countof(bind_data->tex_buffer);
     
    /*for(int i = 0;i<SLG_D3D12_RESOURCE_BUFFER_LIMIT;i++){
        if(bind_data->const_buffer[i].data_ptr){
            num_csv_buffers++;
        }
        if(bind_data->tex_buffer[i].data_ptr){
            num_csv_buffers++;
            num_samplers++;
        }
        
    }*/
   

    //bind.data_ptr->num_cbv_heap = num_csv_buffers;
    //bind.data_ptr->num_samplers_heap = num_samplers;
    
    bind.data_ptr->cbv_srv_uav_heap = slg_make_heap(&(slg_heap_desc){
        .descriptor_heap_type = SLG_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
        .num_buffers = 8,
        .Flags = SLG_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE
    });
    //bind.data_ptr->sampler_heap = bind_data.sampler_heap;
    bind.data_ptr->sampler_heap = slg_make_heap(&(slg_heap_desc){
        .descriptor_heap_type = SLG_DESCRIPTOR_HEAP_TYPE_SAMPLER,
        .num_buffers = 8,
        .Flags = SLG_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE
    });

    D3D12_CPU_DESCRIPTOR_HANDLE cpu_base_handle = {0};
    bind.data_ptr->cbv_srv_uav_heap.data_ptr->heap->lpVtbl->GetCPUDescriptorHandleForHeapStart(bind.data_ptr->cbv_srv_uav_heap.data_ptr->heap,&cpu_base_handle);
    D3D12_GPU_DESCRIPTOR_HANDLE gpu_base_handle = {0};
    bind.data_ptr->cbv_srv_uav_heap.data_ptr->heap->lpVtbl->GetGPUDescriptorHandleForHeapStart(bind.data_ptr->cbv_srv_uav_heap.data_ptr->heap,&gpu_base_handle);

    int inc_size = desc.device->lpVtbl->GetDescriptorHandleIncrementSize(desc.device,_slg_d3d12_convert_descriptor_heap_type(bind.data_ptr->cbv_srv_uav_heap.data_ptr->descriptor_heap_type));
    
    D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_handle = cpu_base_handle;

    bind_data->uniforms.bind_func(bind_data->uniforms.uniforms,&bind);

    int cbv_srv_uav_heap_index = 0;
    bool found_srv = false;
    for(int i = 0;i < SLG_D3D12_RESOURCE_BUFFER_LIMIT; i++){
        /*if(bind.data_ptr->srv_buffer[i].data_ptr != NULL){
            
            //bind.data_ptr->srv_buffer[i] = bind_data->resource_buffer[i]
            //DUMB KID SOLUTION FOR MY DUMB BAD ARCHITECTURE
            bind.data_ptr->srv_buffer[i].data_ptr->texture = bind_data->resource_buffer[i].data_ptr->buffer;
            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {0};
            srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
            //THERE NEEDS TO BE MORE CONFIGURATION FOR THIS
            cbv_srv_uav_handle.ptr = cpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
            desc.device->lpVtbl->CreateShaderResourceView(desc.device,bind.data_ptr->srv_buffer[i].data_ptr->texture,&srvDesc,cbv_srv_uav_handle);
            if(!found_srv){
                bind.data_ptr->srv_heap_start = gpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
                found_srv = true;
            }
            cbv_srv_uav_heap_index++;
        }*/
        if(bind.data_ptr->srv_buffer[i].data_ptr != NULL){
            D3D12_RESOURCE_DESC temp_desc = {0};
            //bind_data->tex_buffer[i].data_ptr->texture->lpVtbl->GetDesc(bind_data->tex_buffer[i].data_ptr->texture,&temp_desc);
            bind.data_ptr->srv_buffer[i].data_ptr->texture->lpVtbl->GetDesc(bind.data_ptr->srv_buffer[i].data_ptr->texture,&temp_desc);
            //bind.data_ptr->num_textures++;
            //bind.data_ptr->num_samplers++;
            //bind.data_ptr->srv_buffer[i] = bind_data->tex_buffer[i];

            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {0};
            srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            if(temp_desc.DepthOrArraySize == 6 && temp_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D){
                srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBE;
                srvDesc.Texture2DArray.MostDetailedMip = 0;
                srvDesc.Texture2DArray.MipLevels = 1;
                srvDesc.Texture2DArray.FirstArraySlice = 0;
                //srvDesc.Texture2DArray.ArraySize = 6;
            }
            else{
                srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            }
            srvDesc.Texture2D.MipLevels = 1;
            
            cbv_srv_uav_handle.ptr = cpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
            desc.device->lpVtbl->CreateShaderResourceView(desc.device,bind.data_ptr->srv_buffer[i].data_ptr->texture,&srvDesc,cbv_srv_uav_handle);
            
            if(!found_srv){
                bind.data_ptr->srv_heap_start = gpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
                found_srv = true;
            }
            cbv_srv_uav_heap_index++;
        }
    }
    bool found_crv = false;
    for(int i = 0;i < SLG_D3D12_RESOURCE_BUFFER_LIMIT; i++){
        if(bind.data_ptr->const_buffer[i].data_ptr != NULL){
            //bind.data_ptr->num_constant_buffers++;
            //bind.data_ptr->const_buffer[i] = bind_data->resource_buffer[i+8];
            D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {0};
            cbvDesc.BufferLocation = bind.data_ptr->const_buffer[i].data_ptr->buffer->lpVtbl->GetGPUVirtualAddress(bind.data_ptr->const_buffer[i].data_ptr->buffer);
            cbvDesc.SizeInBytes = (bind.data_ptr->const_buffer[i].data_ptr->buffer_size + 255) & ~255;
            
            cbv_srv_uav_handle.ptr = cpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
            desc.device->lpVtbl->CreateConstantBufferView(desc.device,&cbvDesc,cbv_srv_uav_handle);

            if(!found_crv){
                bind.data_ptr->cbv_heap_start = gpu_base_handle.ptr + (inc_size * cbv_srv_uav_heap_index);
                found_crv = true;
            }
            cbv_srv_uav_heap_index++;
        }        
    }
    
    /*
    D3D12_CPU_DESCRIPTOR_HANDLE base_srv_handle = {0};
    bind.data_ptr->srv_heap.data_ptr->heap->lpVtbl->GetCPUDescriptorHandleForHeapStart(bind.data_ptr->srv_heap.data_ptr->heap,&base_srv_handle);
    D3D12_CPU_DESCRIPTOR_HANDLE srv_handle = base_srv_handle;
    int srv_inc = desc.device->lpVtbl->GetDescriptorHandleIncrementSize(desc.device,_slg_d3d12_convert_descriptor_heap_type(bind.data_ptr->srv_heap.data_ptr->descriptor_heap_type));
    for(int i = 0;i < SLG_D3D12_RESOURCE_BUFFER_LIMIT;i++){
        SLG_ASSERT(bind_data->tex_buffer[i].data_ptr == NULL || bind_data->resource_buffer[i].data_ptr == NULL && "SRV and TEX bound to the same slot");
        if(bind_data->tex_buffer[i].data_ptr != NULL){ //IF THERE'S TEXTURE
            D3D12_RESOURCE_DESC temp_desc = {0};
            bind_data->tex_buffer[i].data_ptr->texture->lpVtbl->GetDesc(bind_data->tex_buffer[i].data_ptr->texture,&temp_desc);
            //bind.data_ptr->num_textures++;
            //bind.data_ptr->num_samplers++;
            bind.data_ptr->srv_buffer[i] = bind_data->tex_buffer[i];

            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {0};
            srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            if(temp_desc.DepthOrArraySize == 6 && temp_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D){
                srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBE;
                srvDesc.Texture2DArray.MostDetailedMip = 0;
                srvDesc.Texture2DArray.MipLevels = 1;
                srvDesc.Texture2DArray.FirstArraySlice = 0;
                //srvDesc.Texture2DArray.ArraySize = 6;
            }
            else{
                srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            }
            srvDesc.Texture2D.MipLevels = 1;
            
            desc.device->lpVtbl->CreateShaderResourceView(desc.device,bind_data->tex_buffer[i].data_ptr->texture,&srvDesc,srv_handle);
            srv_handle.ptr = base_srv_handle.ptr + (srv_inc * i);

        }
        else if(bind_data->resource_buffer[i].data_ptr != NULL){//IF THERE'S SRV BUFFER
            //HAVEN'T IMPLEMENTED SRV's YET
        }
    }*/
   
    //UAV DOESNT REALLY MATTER RIGHT NOW
    /*
    D3D12_CPU_DESCRIPTOR_HANDLE uav_handle = {0};
    bind.data_ptr->cbv_heap.data_ptr->heap->lpVtbl->GetCPUDescriptorHandleForHeapStart(bind.data_ptr->cbv_heap.data_ptr->heap,&uav_handle);
    for(int i = 0;i < SLG_D3D12_RESOURCE_BUFFER_LIMIT; i++){    
        //bind.data_ptr->num_constant_buffers++;
        bind.data_ptr->const_buffer[i] = bind_data->resource_buffer[i];
        D3D12_CONSTANT_BUFFER_VIEW_DESC uavDesc = {0};
        uavDesc.BufferLocation = bind.data_ptr->const_buffer[i].data_ptr->buffer->lpVtbl->GetGPUVirtualAddress(bind.data_ptr->const_buffer[i].data_ptr->buffer);
        uavDesc.SizeInBytes = (bind.data_ptr->const_buffer[i].data_ptr->buffer_size + 255) & ~255;
        
        desc.device->lpVtbl->CreateConstantBufferView(desc.device,&uavDesc,uav_handle);

        uav_handle.ptr += desc.device->lpVtbl->GetDescriptorHandleIncrementSize(desc.device,_slg_d3d12_convert_descriptor_heap_type(bind.data_ptr->uav_heap.data_ptr->descriptor_heap_type));
                
    }
    */
    //i dont like the way that this is

    return bind;
}


//===============================================================================//
//                                                                               // 
//                              SLUGS FUNCTIONS                                  // 
//                                                                               // 
//===============================================================================//
slg_shader slg_make_shader(slg_shader_desc* shader_desc){
    slg_shader shd;
    shd = _slg_d3d12_make_shader(shader_desc);
    return shd;
}

void slg_default_pipeline_desc(slg_pipeline_desc* desc){
   
    //desc->depth_desc.depth_bias = (desc->depth_desc.depth_bias==0) ? 0 : desc->depth_desc.depth_bias;
    desc->rasterizer_desc.depth_bias = _slg_check_defaults(desc->rasterizer_desc.depth_bias,0);
    //desc->depth_desc.depth_bias_clamp = (desc->depth_desc.depth_bias_clamp == 0.0f) ? 0.0f : desc->depth_desc.depth_bias_clamp;
    desc->rasterizer_desc.depth_bias_clamp = _slg_check_defaults(desc->rasterizer_desc.depth_bias_clamp,0.0f);
    //desc->depth_desc.slope_scaled_depth_bias = (desc->depth_desc.slope_scaled_depth_bias == 0.0f) ? 0.0f : desc->depth_desc.slope_scaled_depth_bias;
    desc->rasterizer_desc.slope_scaled_depth_bias = _slg_check_defaults(desc->rasterizer_desc.slope_scaled_depth_bias,0.0f);
    //desc->cull_mode = (desc->cull_mode == DS_CULL_MODE_DEFAULT) ? DS_CULL_MODE_BACK : desc->cull_mode;

    

    desc->rasterizer_desc.cull_mode = _slg_check_defaults(desc->rasterizer_desc.cull_mode,SLG_CULL_MODE_BACK); 
    desc->rasterizer_desc.fill_mode = _slg_check_defaults(desc->rasterizer_desc.fill_mode, SLG_FILL_MODE_SOLID);

    desc->rasterizer_desc.facewinding_mode = _slg_check_defaults(desc->rasterizer_desc.facewinding_mode,SLG_FACEWINDING_COUNTERCLOCKWISE);
 

      //bs.RenderTarget[i].DestBlendAlpha = D3D12_BLEND_ZERO;
        //bs.RenderTarget[i].BlendOpAlpha = D3D12_BLEND_OP_ADD;
        //bs.RenderTarget[i].LogicOp = D3D12_LOGIC_OP_NOOP;
    //doing blending now
    
    //we are just gonna assume that all the bools are good being false
    desc->blend_desc.src_blend = _slg_check_defaults(desc->blend_desc.src_blend,SLG_BLEND_ONE);
    desc->blend_desc.dest_blend = _slg_check_defaults(desc->blend_desc.dest_blend,SLG_BLEND_ZERO);
    desc->blend_desc.blend_op = _slg_check_defaults(desc->blend_desc.blend_op,SLG_BLEND_OP_ADD);
    desc->blend_desc.src_blend_alpha = _slg_check_defaults(desc->blend_desc.src_blend_alpha,SLG_BLEND_ONE);
    desc->blend_desc.dest_blend_alpha = _slg_check_defaults(desc->blend_desc.dest_blend_alpha,SLG_BLEND_ZERO);
    desc->blend_desc.blend_op_alpha = _slg_check_defaults(desc->blend_desc.blend_op_alpha,SLG_BLEND_OP_ADD);
    
    desc->blend_desc.logic_op = _slg_check_defaults(desc->blend_desc.logic_op,SLG_LOGIC_OP_NOOP);

    if((desc->blend_desc.color_write_enable.alpha_enable | desc->blend_desc.color_write_enable.red_enable | desc->blend_desc.color_write_enable.blue_enable | desc->blend_desc.color_write_enable.green_enable) == 0){
        desc->blend_desc.color_write_enable.alpha_enable = 1;
        desc->blend_desc.color_write_enable.blue_enable = 1;
        desc->blend_desc.color_write_enable.green_enable = 1;
        desc->blend_desc.color_write_enable.red_enable = 1;
    }
    
    desc->rasterizer_desc.conservative_rasterization_mode = _slg_check_defaults(desc->rasterizer_desc.conservative_rasterization_mode,SLG_CONSERVATIVE_RASTERIZATION_MODE_OFF);
    desc->primitive_topology_type = _slg_check_defaults(desc->primitive_topology_type,SLG_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE);

    desc->num_render_targets = _slg_check_defaults(desc->num_render_targets,1);

    desc->sample_count = _slg_check_defaults(desc->sample_count,1);
    desc->sample_mask = _slg_check_defaults(desc->sample_mask,UINT_MAX);

    return;
}

slg_pipeline slg_make_pipeline(slg_pipeline_desc* pipeline_desc){
    slg_pipeline pip;
    pip = _slg_d3d12_make_pipeline(pipeline_desc);
    return pip;
}

slg_bindings slg_make_bindings(slg_bindings_desc* binding_desc){
    slg_bindings bind;
    bind = _slg_d3d12_make_bindings(binding_desc);
    return bind;
    //bind = 
}


//THIS MIGHT BECOME DX12 ONLY BACKEND, BECAUSE IM NOT SURE THE OTHERS BACKENDS NEED TO MAKE HEAPS LIKE THIS
//ITS ALSO USED EXCLUSIVELY IN THE MAKE BINDINGS SECTION 
slg_heap slg_make_heap(slg_heap_desc* heap_desc){
    
    slg_desc_t desc = slg_d3d12_state.desc;
 
    slg_heap heap;
    heap.data_ptr = pool_alloc(&slg_pools.heap_pool);
    //FIXME: maybe we should check for defaults/assert that everything is correct
    D3D12_DESCRIPTOR_HEAP_DESC dx_heapDesc = {0};
    dx_heapDesc.NumDescriptors = heap_desc->num_buffers; // one descriptor for now
    dx_heapDesc.Type = _slg_d3d12_convert_descriptor_heap_type(heap_desc->descriptor_heap_type);
    dx_heapDesc.Flags = _slg_d3d12_convert_descriptor_heap_flags(heap_desc->Flags);


    d3d12_throwIfFailed(desc.device->lpVtbl->CreateDescriptorHeap(desc.device,&dx_heapDesc,&IID_ID3D12DescriptorHeap,(void**)&heap.data_ptr->heap));
    heap.data_ptr->descriptor_heap_type = heap_desc->descriptor_heap_type;
    return heap;
        //CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&descriptorHeap));

}

slg_texture slg_make_texture(slg_texture_desc* tex_desc){
    slg_texture tex;
    tex = _slg_d3d12_make_texture(tex_desc);
    return tex;
}

slg_buffer slg_make_buffer(slg_buffer_desc* buffer_desc){
    slg_desc_t desc = slg_d3d12_state.desc;
    slg_buffer buf = {0};
    buf.data_ptr = pool_alloc(&slg_pools.buffer_pool);
    
    D3D12_HEAP_PROPERTIES heap_props;
    heap_props.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heap_props.Type = D3D12_HEAP_TYPE_UPLOAD;
    heap_props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    heap_props.CreationNodeMask = 1;
    heap_props.VisibleNodeMask = 1;
    uint64_t aligned_size;
    if(buffer_desc->usage == SLG_BUFFER_USAGE_CONSTANT_BUFFER){
        aligned_size = (buffer_desc->buffer_size+255) & ~255;
    }
    else{
        aligned_size = buffer_desc->buffer_size;
    }
   
    D3D12_RESOURCE_DESC resource_desc;
    resource_desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
    resource_desc.Alignment = 0;
    resource_desc.Width = aligned_size;
    resource_desc.Height = 1;
    resource_desc.DepthOrArraySize = 1;
    resource_desc.MipLevels = 1;
    resource_desc.Format = DXGI_FORMAT_UNKNOWN;
    resource_desc.SampleDesc.Count = 1;
    resource_desc.SampleDesc.Quality = 0;
    resource_desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    resource_desc.Flags = D3D12_RESOURCE_FLAG_NONE;

    d3d12_throwIfFailed(desc.device->lpVtbl->CreateCommittedResource(desc.device,
        &heap_props,
        D3D12_HEAP_FLAG_NONE,
        &resource_desc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        NULL,
        &IID_ID3D12Resource,
        (void**)&buf.data_ptr->buffer
    ));
    
    UINT8* pDataBegin;
    D3D12_RANGE readRange = {0,0};
    d3d12_throwIfFailed(buf.data_ptr->buffer->lpVtbl->Map(buf.data_ptr->buffer,
        0, &readRange, (void**)(&pDataBegin)));

    void* test = memcpy(pDataBegin, buffer_desc->buffer, buffer_desc->buffer_size);
    SLG_ASSERT(test != NULL && "memcpy fail");
    buf.data_ptr->buffer->lpVtbl->Unmap(buf.data_ptr->buffer, 0, NULL);

    if(buffer_desc->usage == SLG_BUFFER_USAGE_CONSTANT_BUFFER){
        buf.data_ptr->buffer_size = (UINT)aligned_size;
    }
    else{
        buf.data_ptr->buffer_size = buffer_desc->buffer_size;
    }
    
    buf.data_ptr->buffer_stride = buffer_desc->buffer_stride;
    return buf;
}

void slg_update_buffer(slg_buffer buf, void* buffer_data, unsigned int buffer_size){
    UINT8* pDataBegin;
    D3D12_RANGE readRange = {0,0};
    d3d12_throwIfFailed(buf.data_ptr->buffer->lpVtbl->Map(buf.data_ptr->buffer,
        0, &readRange, (void**)(&pDataBegin)));
    memcpy(pDataBegin, buffer_data, buffer_size);
    buf.data_ptr->buffer->lpVtbl->Unmap(buf.data_ptr->buffer, 0, NULL); // safely unmap after update
}


//we need to pass the vertex data into the here somehow

void slg_init_pools(){
    
    slg_pools.pipelinePoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.pipeline_pool,slg_pools.pipelinePoolBackingBuffer,262144,sizeof(slg_pipeline_t),DEFAULT_ALIGN);
    //slg_pools.shaderFileReferenceBackingBuffer = malloc(65536);
    //pool_init(&slg_pools.shaderFileReferencePool,slg_pools.shaderFileReferenceBackingBuffer,65536,sizeof(slg_shader_source_data),DEFAULT_ALIGN);
    slg_pools.shaderPoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.shader_pool,slg_pools.shaderPoolBackingBuffer,262144,sizeof(slg_shader_t),DEFAULT_ALIGN);
    slg_pools.bufferPoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.buffer_pool,slg_pools.bufferPoolBackingBuffer,262144,sizeof(slg_buffer_t),DEFAULT_ALIGN);
    slg_pools.bindingPoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.binding_pool,slg_pools.bindingPoolBackingBuffer,262144,sizeof(slg_bindings_t),DEFAULT_ALIGN);
    slg_pools.heapPoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.heap_pool,slg_pools.heapPoolBackingBuffer,262144,sizeof(slg_heap_t),DEFAULT_ALIGN);
    slg_pools.texturePoolBackingBuffer = malloc(262144);
    pool_init(&slg_pools.texture_pool,slg_pools.texturePoolBackingBuffer,262144,sizeof(slg_texture_t),DEFAULT_ALIGN);

}

void _slg_d3d12_setup(){
    //THIS IS NOT GREAT
    //I just kinda want to get something up and running for the time being
    
    slg_d3d12_state.appdata.d3d12_scissor_rect.left = 0;
    slg_d3d12_state.appdata.d3d12_scissor_rect.top = 0;
    SLG_ASSERT(slg_d3d12_state.appdata.width > 0 && "width is 0");
    SLG_ASSERT(slg_d3d12_state.appdata.height > 0 && "height is 0");
    slg_d3d12_state.appdata.d3d12_scissor_rect.right = slg_d3d12_state.appdata.width;
    slg_d3d12_state.appdata.d3d12_scissor_rect.bottom = slg_d3d12_state.appdata.height;

    slg_d3d12_state.appdata.d3d12_viewport.TopLeftX = 0;
    slg_d3d12_state.appdata.d3d12_viewport.TopLeftY = 0;
    slg_d3d12_state.appdata.d3d12_viewport.Width = (float)slg_d3d12_state.appdata.width;
    slg_d3d12_state.appdata.d3d12_viewport.Height = (float)slg_d3d12_state.appdata.height;
    slg_d3d12_state.appdata.d3d12_viewport.MinDepth = D3D12_MIN_DEPTH;
    slg_d3d12_state.appdata.d3d12_viewport.MaxDepth = D3D12_MAX_DEPTH;

    _slg_d3d12_CreateDeviceAndSwapChain(&slg_d3d12_state.desc,&slg_d3d12_state.frame_buf,&slg_d3d12_state.fence);
    _slg_d3d12_CreateRenderTarget(slg_d3d12_state.desc,&slg_d3d12_state.frame_buf);
    _slg_d3d12_CreateRTVHandle(slg_d3d12_state.desc,&slg_d3d12_state.frame_buf);
    _slg_d3d12_CreateDepthBuffer(&slg_d3d12_state.desc,&slg_d3d12_state.appdata,&slg_d3d12_state.frame_buf);
    //_slg_d3d12_CreateCommandAllocator(&slg_d3d12_state.desc);
    for(int i = 0;i<FrameCount;i++){
        _slg_d3d12_CreateCommandAllocator(slg_d3d12_state.desc.device,&slg_d3d12_state.frame_buf.frame_context[i].commandAllocator);
        _slg_d3d12_CreateCommandList(slg_d3d12_state.desc.device,slg_d3d12_state.frame_buf.frame_context[i].commandAllocator,&slg_d3d12_state.frame_buf.frame_context[i].commandList);

    }

    //_slg_d3d12_CreateCommandList(&slg_d3d12_state.desc);
    
    for(int i = 0;i<FrameCount;i++){
        //slg_d3d12_state.fence.fenceValue[i] = 0;
        slg_d3d12_state.frame_buf.frame_context[i].fenceValue = 1;
    }
    //slg_d3d12_state.fence.frameIndex = 0;
    slg_d3d12_state.frame_buf.frameIndex = 0; 
    slg_d3d12_state.frame_buf.currentFenceValue = 1;
    _slg_d3d12_CreateFence();
    //slg_d3d12_state.desc.commandQueue->lpVtbl->Signal(slg_d3d12_state.fence.fence->fence, 0);

}

void slg_setup(){// INITIALIZE SOME OF THE REQUIRED THINGS
    #ifdef SLG_HOT_RELOADING
        old_queue.max_pips = 25;
        old_queue.num_pips = 0;
    #endif
    slg_init_pools();
    _slg_d3d12_setup();
}

void _slg_d3d12_close_setup() {
    slg_framebuffer_t* frame_buf = &slg_d3d12_state.frame_buf;
    slg_desc_t* desc = &slg_d3d12_state.desc;

    for (UINT i = 0; i < FrameCount; i++) {
        ID3D12GraphicsCommandList* command_list = frame_buf->frame_context[i].commandList;

        // Close and execute each command list
        d3d12_throwIfFailed(command_list->lpVtbl->Close(command_list));
        ID3D12CommandList* ppCommandLists[] = { (ID3D12CommandList*)command_list };
        desc->commandQueue->lpVtbl->ExecuteCommandLists(desc->commandQueue, 1, ppCommandLists);
    }

    // Wait for GPU to ensure all setup commands are finished
    d3d12_waitForGPU();

    
}

void slg_close_setup(){
    _slg_d3d12_close_setup();
}

void _slg_d3d12_begin_frame(){
    slg_framebuffer_t* frame_buf = &slg_d3d12_state.frame_buf;
    slg_fence_t* fence = &slg_d3d12_state.fence;

    frame_buf->frameIndex = frame_buf->swapchain->lpVtbl->GetCurrentBackBufferIndex(frame_buf->swapchain);
    slg_frame_context_t* frame_context = &frame_buf->frame_context[frame_buf->frameIndex];

    // Wait for GPU to finish with this frame
    if(fence->fence->lpVtbl->GetCompletedValue(fence->fence) < frame_context->fenceValue){
        fence->fence->lpVtbl->SetEventOnCompletion(fence->fence, frame_context->fenceValue, fence->fenceEvent);
        WaitForSingleObject(fence->fenceEvent, INFINITE);
    }

    // Reset allocator + list for this frame
    frame_context->commandAllocator->lpVtbl->Reset(frame_context->commandAllocator);
    frame_context->commandList->lpVtbl->Reset(frame_context->commandList, frame_context->commandAllocator, NULL);
}
void slg_begin_frame(){
    
    #ifdef SLG_D3D12
    _slg_d3d12_begin_frame();
    #endif
}
void _slg_d3d12_begin_pass(){
    slg_desc_t* desc = &slg_d3d12_state.desc;
    slg_framebuffer_t frame_buf = slg_d3d12_state.frame_buf;
    slg_fence_t* fence = &slg_d3d12_state.fence;
    slg_app_data_t* app_data = &slg_d3d12_state.appdata;

        
    //d3d12_throwIfFailed(desc->commandAllocator->lpVtbl->Reset(desc->commandAllocator));
    ID3D12GraphicsCommandList* command_list = frame_buf.frame_context[frame_buf.frameIndex].commandList;   
    ID3D12CommandAllocator* command_allocator = frame_buf.frame_context[frame_buf.frameIndex].commandAllocator;   
    //d3d12_throwIfFailed(command_allocator->lpVtbl->Reset(command_allocator));
    //d3d12_throwIfFailed(desc->commandList->lpVtbl->Reset(desc->commandList,desc->commandAllocator,NULL));

    //desc->commandList->lpVtbl->RSSetViewports(desc->commandList,1,&app_data->d3d12_viewport);
    //desc->commandList->lpVtbl->RSSetScissorRects(desc->commandList,1,&app_data->d3d12_scissor_rect);

    command_list->lpVtbl->RSSetViewports(command_list,1,&app_data->d3d12_viewport);
    command_list->lpVtbl->RSSetScissorRects(command_list,1,&app_data->d3d12_scissor_rect);    

    D3D12_RESOURCE_BARRIER barrier;
    barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier.Transition.pResource = frame_buf.frame_context[frame_buf.frameIndex].renderTarget;
    barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

    command_list->lpVtbl->ResourceBarrier(command_list,1,&barrier);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = frame_buf.frame_context[frame_buf.frameIndex].rtvHandle;
    //frame_buf.rtvHeap->lpVtbl->GetCPUDescriptorHandleForHeapStart(frame_buf.rtvHeap,&rtvHandle);
    //rtvHandle.ptr += (size_t)fence->frameIndex * (size_t)frame_buf.rtvDescriptorSize;

    D3D12_CPU_DESCRIPTOR_HANDLE depthHandle = frame_buf.frame_context[frame_buf.frameIndex].depthHandle;
    //frame_buf.depthStencilHeap->lpVtbl->GetCPUDescriptorHandleForHeapStart(frame_buf.depthStencilHeap,&depthHandle);
    command_list->lpVtbl->OMSetRenderTargets(command_list,1,&rtvHandle,false,&depthHandle);
    const float clearColor[] = {1.0f,0.2f,0.4f,1.0f};
    command_list->lpVtbl->ClearRenderTargetView(command_list,rtvHandle,clearColor,0,NULL);
    command_list->lpVtbl->ClearDepthStencilView(command_list,
        depthHandle,
        D3D12_CLEAR_FLAG_DEPTH,
        1.0f,   // depth = farthest
        0,      // stencil clear
        0,
        NULL
    );
}

void slg_begin_pass(){
    _slg_d3d12_begin_pass();
}

void _slg_d3d12_set_pipeline(slg_pipeline* pip){
    slg_framebuffer_t* frame_buf = &slg_d3d12_state.frame_buf;
    ID3D12GraphicsCommandList* command_list = frame_buf->frame_context[frame_buf->frameIndex].commandList;

    command_list->lpVtbl->SetPipelineState(command_list, pip->data_ptr->pipeline_state);
    command_list->lpVtbl->SetGraphicsRootSignature(command_list, pip->data_ptr->root_signature);
}

void slg_set_pipeline(slg_pipeline* pip){
    _slg_d3d12_set_pipeline(pip);
}

void _slg_d3d12_set_bindings(slg_bindings* bind){
    slg_desc_t* desc = &slg_d3d12_state.desc;
    slg_framebuffer_t frame_buf = slg_d3d12_state.frame_buf;
    ID3D12GraphicsCommandList* command_list = frame_buf.frame_context[frame_buf.frameIndex].commandList;   

    command_list->lpVtbl->IASetPrimitiveTopology(command_list,D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    D3D12_VERTEX_BUFFER_VIEW vert_buffer_view;
    vert_buffer_view.BufferLocation = bind->data_ptr->vertex_buffer.data_ptr->buffer->lpVtbl->GetGPUVirtualAddress(bind->data_ptr->vertex_buffer.data_ptr->buffer);
    vert_buffer_view.StrideInBytes = bind->data_ptr->vertex_buffer.data_ptr->buffer_stride;
    vert_buffer_view.SizeInBytes = bind->data_ptr->vertex_buffer.data_ptr->buffer_size;

    D3D12_INDEX_BUFFER_VIEW index_buffer_view;
    index_buffer_view.BufferLocation = bind->data_ptr->index_buffer.data_ptr->buffer->lpVtbl->GetGPUVirtualAddress(bind->data_ptr->index_buffer.data_ptr->buffer);
    index_buffer_view.SizeInBytes = bind->data_ptr->index_buffer.data_ptr->buffer_size;
    index_buffer_view.Format = DXGI_FORMAT_R16_UINT;

    command_list->lpVtbl->IASetVertexBuffers(command_list,0,1,&vert_buffer_view);
    command_list->lpVtbl->IASetIndexBuffer(command_list,&index_buffer_view);
   
    ID3D12DescriptorHeap* heaps[] = {
        bind->data_ptr->cbv_srv_uav_heap.data_ptr->heap,
        bind->data_ptr->sampler_heap.data_ptr->heap
    };
    /*if(bind->data_ptr->num_cbv_heap>0){
        heaps[num_heaps] = bind->data_ptr->cbv_heap.data_ptr->heap;
        num_heaps++;
    }
    if(bind->data_ptr->num_samplers_heap > 0){
        heaps[num_heaps] = bind->data_ptr->sampler_heap.data_ptr->heap;
        num_heaps++;
    }*/
    command_list->lpVtbl->SetDescriptorHeaps(command_list,2,heaps);
    
    
    D3D12_GPU_DESCRIPTOR_HANDLE cbv_handle = {0};
    //bind->data_ptr->cbv_srv_uav_heap.data_ptr->heap->lpVtbl->GetGPUDescriptorHandleForHeapStart(bind->data_ptr->cbv_srv_uav_heap.data_ptr->heap,&cbv_handle);
    cbv_handle.ptr = bind->data_ptr->cbv_heap_start;
    command_list->lpVtbl->SetGraphicsRootDescriptorTable(command_list,0,cbv_handle);
    D3D12_GPU_DESCRIPTOR_HANDLE srv_handle = {0};
    srv_handle.ptr = bind->data_ptr->srv_heap_start;
    bind->data_ptr->cbv_srv_uav_heap.data_ptr->heap->lpVtbl->GetGPUDescriptorHandleForHeapStart(bind->data_ptr->cbv_srv_uav_heap.data_ptr->heap,&cbv_handle);
    command_list->lpVtbl->SetGraphicsRootDescriptorTable(command_list,1,cbv_handle);
    D3D12_GPU_DESCRIPTOR_HANDLE sampler_handle = {0};
    bind->data_ptr->sampler_heap.data_ptr->heap->lpVtbl->GetGPUDescriptorHandleForHeapStart(bind->data_ptr->sampler_heap.data_ptr->heap,&sampler_handle);
    command_list->lpVtbl->SetGraphicsRootDescriptorTable(command_list,3,sampler_handle);
    
    
    /*
    need to do the constant buffers here
    */
}

void slg_set_bindings(slg_bindings* bind){
    _slg_d3d12_set_bindings(bind);
}

void _slg_d3d12_draw(unsigned int index_count_per_instance,unsigned int instance_count,unsigned int start_index_location,int base_vertex_location,unsigned int start_instance_location){
    slg_desc_t *desc = &slg_d3d12_state.desc;
    slg_framebuffer_t frame_buf = slg_d3d12_state.frame_buf;
    ID3D12GraphicsCommandList* command_list = frame_buf.frame_context[frame_buf.frameIndex].commandList;   
    //slg_framebuffer_t* frame_buf = &slg_d3d12_state.frame_buf;
    //slg_fence_t* fence = &slg_d3d12_state.fence;
    
    command_list->lpVtbl->DrawIndexedInstanced(command_list,index_count_per_instance,instance_count,start_index_location,base_vertex_location,start_instance_location);
    
    //desc->commandList->lpVtbl->IASetVertexBuffers(desc->commandList,0,1,&);
}

void slg_draw(unsigned int index_count_per_instance,unsigned int instance_count,unsigned int start_index_location,int base_vertex_location,unsigned int start_instance_location){
    _slg_d3d12_draw(index_count_per_instance,instance_count,start_index_location,base_vertex_location,start_instance_location);    
}

void _slg_d3d12_submit_draw(){
    slg_desc_t* desc = &slg_d3d12_state.desc;
    slg_fence_t* fence = &slg_d3d12_state.fence;

    slg_framebuffer_t* frame_buf = &slg_d3d12_state.frame_buf;
    ID3D12GraphicsCommandList* command_list = frame_buf->frame_context[frame_buf->frameIndex].commandList;   
    //slg_app_data_t* app_data = &slg_d3d12_state.appdata;

    D3D12_RESOURCE_BARRIER barrier_close;
    barrier_close.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier_close.Flags =  D3D12_RESOURCE_BARRIER_FLAG_NONE;
    barrier_close.Transition.pResource   = frame_buf->frame_context[frame_buf->frameIndex].renderTarget;
    barrier_close.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    barrier_close.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    barrier_close.Transition.StateAfter  = D3D12_RESOURCE_STATE_PRESENT;

    command_list->lpVtbl->ResourceBarrier(command_list,1,&barrier_close);
   
    d3d12_throwIfFailed(command_list->lpVtbl->Close(command_list));
    ID3D12CommandList* ppCommandLists[] = { (ID3D12CommandList*)command_list };
    desc->commandQueue->lpVtbl->ExecuteCommandLists(desc->commandQueue,_countof(ppCommandLists),ppCommandLists);

    //increment fence value
    frame_buf->currentFenceValue++;
    //signal fence
    d3d12_throwIfFailed(desc->commandQueue->lpVtbl->Signal(desc->commandQueue, fence->fence, frame_buf->currentFenceValue));
    
    d3d12_throwIfFailed(frame_buf->swapchain->lpVtbl->Present(frame_buf->swapchain,1,0));//present
    //advance fence
    slg_frame_context_t* current_frame_context = &frame_buf->frame_context[frame_buf->frameIndex];
    current_frame_context->fenceValue = frame_buf->currentFenceValue;
    frame_buf->frameIndex = frame_buf->swapchain->lpVtbl->GetCurrentBackBufferIndex(frame_buf->swapchain);

    
    //d3d12_waitForPreviousFrame();


    
}

void slg_submit_draw(){
    _slg_d3d12_submit_draw();
}

unsigned long long get_file_access_time(char* file_name){
    char fullPath[MAX_PATH];
    unsigned long long timestamp;
    sprintf(fullPath, "C:\\EngineV2\\%s", file_name);
    HANDLE hFile = CreateFileA(
    fullPath,
    GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL
    );
    
    if(hFile != INVALID_HANDLE_VALUE){
        FILETIME creation_time;
        FILETIME access_time;
        FILETIME write_time;

        if (GetFileTime(hFile, &creation_time, &access_time, &write_time)){
            ULARGE_INTEGER large_write;
            large_write.LowPart = write_time.dwLowDateTime;
            large_write.HighPart = write_time.dwHighDateTime;
            timestamp = large_write.QuadPart;
        }     
    }
    CloseHandle(hFile);
    return timestamp;
}
/*void releasePipelineCallback(PVOID context){
    ID3D12PipelineState* pipeline = (ID3D12PipelineState*) context;
    if(pipeline){
        pipeline->lpVtbl->Release(pipeline);
    }
}*/
/*VOID CALLBACK FenceEventCallback(
    PVOID context,
    BOOLEAN timedOut
)
{
    releasePipelineCallback(context);
}*/
void slg_check_for_hot_reload(){
    #ifndef SLG_HOT_RELOADING
        #error please define SLG_HOT_RELOADING ABOVE SLG_GRAPHICS.H
    #endif

    //can we make a fence object that gets assigned when hot reloading occurs?
    //that way we can tell if the new pipeline can be deployed

    //go through the .hlsl shaders and check if the hlsl shaders are
    //more recent than the cso source files
    //Pool* shader_pool = &slg_pools.shader_pool;
    //
    //size_t num_chunks = shader_pool->buffer_length/shader_pool->chunk_size;
    //it might be smart to make a list of all of the path's for each hlsl file and their corresponding cso files
    //because matching them up like this is gonna be annoying for sure 

    slg_desc_t desc = slg_d3d12_state.desc;
    slg_fence_t fence =  slg_d3d12_state.fence;
    //WIN32_FIND_DATA FindFileData;
    //HANDLE hFind;
    Pool pipeline_pool = slg_pools.pipeline_pool;
    if(pipeline_pool.chunk_size == 0){
        return;
    }
    size_t num_chunks = pipeline_pool.buffer_length/pipeline_pool.chunk_size;

    //iterate through every pipeline to get the shader blobs..
    //the problem is that if we update the shader information for a pipeline that shares a shader,
    //then we will have an issue 

    Arena shader_list_arena;
    unsigned char shader_list_backing_buffer[65536];
    arena_init(&shader_list_arena,shader_list_backing_buffer,65536);
    shader_list_arena.name = "shader_list_arena";
    /*char buffer[128];
    sprintf(buffer, "num chunks: %zd\n", num_chunks);
    OutputDebugStringA(buffer);
    sprintf(buffer, "arena_offset: %zd\n", shader_list_arena.current_offset);
    OutputDebugStringA(buffer);
    */
    slg_shader_t** shader_list = arena_alloc(&shader_list_arena,num_chunks*sizeof(slg_shader_t*));
    int shader_list_count = 0;
    for(int i = 0;i<num_chunks;i++){
        void* ptr = &pipeline_pool.buffer[i*pipeline_pool.chunk_size];
        if(pool_is_chunk_allocated(&pipeline_pool, ptr)){
            slg_pipeline_t* pip_data = (slg_pipeline_t*)ptr;
            slg_shader_t* source_data = pip_data->shader_ptr;
            unsigned long long hlsl_access_time = get_file_access_time(source_data->hlsl_name);
            unsigned long long vert_access_time = get_file_access_time(source_data->vert_shader_cso);
            unsigned long long frag_access_time = get_file_access_time(source_data->frag_shader_cso);
            
            if(hlsl_access_time > vert_access_time || hlsl_access_time > frag_access_time){
                //recompile vert
                //fxc /T ps_5_0 /E PSMain /Fo %%~nf_ps.cso %%f
                char command[MAX_PATH];
                snprintf(command,MAX_PATH,"fxc /T vs_5_0 /E VSMain /Fo %s %s",source_data->vert_shader_cso,source_data->hlsl_name);
                system(command);
             
                //recompile frag
                //char command[MAX_PATH];
                snprintf(command,MAX_PATH,"fxc /T ps_5_0 /E PSMain /Fo %s %s",source_data->frag_shader_cso,source_data->hlsl_name);
                system(command);

                d3d12_waitForGPU();// wait for the gpu to finish what it's doing before updating shader blobs,
                
                if(source_data->VertexShaderBlob){
                    source_data->VertexShaderBlob->lpVtbl->Release(source_data->VertexShaderBlob);
                }
                WCHAR vert_shader_name[MAX_PATH]; 
                d3d12_GetAssetFullPath(source_data->vert_shader_cso,vert_shader_name);
                d3d12_throwIfFailed(D3DReadFileToBlob(vert_shader_name, &source_data->VertexShaderBlob));
                if(source_data->PixelShaderBlob){
                    source_data->PixelShaderBlob->lpVtbl->Release(source_data->PixelShaderBlob);
                }
                WCHAR frag_shader_name[MAX_PATH]; 
                d3d12_GetAssetFullPath(source_data->frag_shader_cso,frag_shader_name);
                d3d12_throwIfFailed(D3DReadFileToBlob(frag_shader_name, &source_data->PixelShaderBlob));
            
                shader_list[shader_list_count] = source_data;
                shader_list_count++;

                //now that we have this, we need to update the pipeline objects
                // I NOW NEED TO KNOW WHAT PIPELINES ARE USING THIS UNFORTUNATELY

                //can I make a list of the pipelines that use the shader or maybe the easier method is to go through 
                //the pools of pipelines and check for the shader that way                
            }
            for(int t = 0;t<shader_list_count;t++){
                if(pip_data->shader_ptr == shader_list[t]){
                    //then we need to remake the shader pipeline with the new shader information
                    D3D12_GRAPHICS_PIPELINE_STATE_DESC new_desc = pip_data->pso_state_desc;
                    new_desc.VS.pShaderBytecode = pip_data->shader_ptr->VertexShaderBlob->lpVtbl->GetBufferPointer(pip_data->shader_ptr->VertexShaderBlob); 
                    new_desc.VS.BytecodeLength = pip_data->shader_ptr->VertexShaderBlob->lpVtbl->GetBufferSize(pip_data->shader_ptr->VertexShaderBlob);
                    new_desc.PS.pShaderBytecode = pip_data->shader_ptr->PixelShaderBlob->lpVtbl->GetBufferPointer(pip_data->shader_ptr->PixelShaderBlob); 
                    new_desc.PS.BytecodeLength = pip_data->shader_ptr->PixelShaderBlob->lpVtbl->GetBufferSize(pip_data->shader_ptr->PixelShaderBlob);

                    new_desc.InputLayout.pInputElementDescs = pip_data->input_element_descs;
                    new_desc.InputLayout.NumElements = pip_data->num_input_elements;
                    //this creates a new pipeline state descriptor
                    //we need to release the old one though

                   
                    //HANDLE pipelineEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
                    ID3D12PipelineState* old_pip = pip_data->pipeline_state;
                    
                    const UINT64 pipelineFence = slg_d3d12_state.frame_buf.frame_context[slg_d3d12_state.frame_buf.frameIndex].fenceValue;
                    //fence.fenceValue[fence.frameIndex]; // dont update this index since it will be updated at the end of the frame
                    SLG_ASSERT(old_queue.num_pips<old_queue.max_pips);
                    if(old_queue.num_pips<old_queue.max_pips){
                        old_queue.pip_queue[old_queue.num_pips].pip = old_pip;
                        old_queue.pip_queue[old_queue.num_pips].fence = pipelineFence;
                        old_queue.num_pips;
                    }
                    //HANDLE m_fenceEvent;
                    
                    //m_fenceEvent = RegisterWaitForSingleObject(&m_fenceEvent,pipelineEvent,FenceEventCallback,(PVOID)old_pip, INFINITE, WT_EXECUTEDEFAULT);
                    //m_commandQueue->Signal(m_fence.Get(), fenceToWaitFor)
                    //d3d12_throwIfFailed(desc.commandQueue->lpVtbl->Signal(desc.commandQueue,&fence.fence,pipelineFence));
                    //fence.fence->lpVtbl->SetEventOnCompletion(fence.fence,pipelineFence,m_fenceEvent);
                    d3d12_throwIfFailed(desc.device->lpVtbl->CreateGraphicsPipelineState(desc.device,&new_desc,&IID_ID3D12PipelineState,(void**)&pip_data->pipeline_state)); 
                    //we need to bundle the pipeline with a fence value
                    
                }
            }
            //the gpu should be done so we can update the pipelines
            //pip_data = slg_make_pipeline();
            
            
           
        }
        
    }
    for(int i = 0;i < old_queue.num_pips;i++){
        if(slg_d3d12_state.frame_buf.frame_context[slg_d3d12_state.frame_buf.frameIndex].fenceValue > old_queue.pip_queue[i].fence){
            old_queue.pip_queue[i].pip->lpVtbl->Release(old_queue.pip_queue[i].pip);
            for(int t = i+1;t<old_queue.num_pips;t++){
                //go through the remaining items in the queue and move them down
                old_queue.pip_queue[t-1] = old_queue.pip_queue[t];

            }
            old_queue.num_pips--;
        }
    }
    arena_free_all(&shader_list_arena);
    //once the gpu is done we can rese
    


    //okay we need recompile the shader resource and then rebuild the process again
    //
    /*
    hFind = FindFirstFile("C:\\EngineV2\\*.*",&FindFileData);
    bool found_file = FindNextFile(hFind, &FindFileData);
    while(found_file){
        char* file_handle = strstr(FindFileData.cFileName,".hlsl");
        if(file_handle){

            char fullPath[MAX_PATH];
            sprintf(fullPath, "C:\\EngineV2\\%s", FindFileData.cFileName);
            HANDLE hFile = CreateFileA(
            fullPath,
            GENERIC_READ,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            NULL,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            NULL
            );
            if(hFile != INVALID_HANDLE_VALUE){
                FILETIME creation_time;
                FILETIME access_time;
                FILETIME write_time;

                if (GetFileTime(hFile, &creation_time, &access_time, &write_time)){
                    ULARGE_INTEGER large_write;
                    large_write.LowPart = write_time.dwLowDateTime;
                    large_write.HighPart = write_time.dwHighDateTime;
                    unsigned long long timestamp = large_write.QuadPart;
                    int break_point = 0;
                }     
            }
           

        }
        

        found_file = FindNextFile(hFind,&FindFileData);
    }
    return false;
    */
}


void _slg_d3d12_destroy_desc(void) {
    /*if (slg_d3d12_state.desc.commandAllocator) {
        slg_d3d12_state.desc.commandAllocator->lpVtbl->Release(slg_d3d12_state.desc.commandAllocator);
        slg_d3d12_state.desc.commandAllocator = NULL;
    }*/

    /*if (slg_d3d12_state.desc.commandList) {
        slg_d3d12_state.desc.commandList->lpVtbl->Release(slg_d3d12_state.desc.commandList);
        slg_d3d12_state.desc.commandList = NULL;
    }*/

    if (slg_d3d12_state.desc.commandQueue) {
        slg_d3d12_state.desc.commandQueue->lpVtbl->Release(slg_d3d12_state.desc.commandQueue);
        slg_d3d12_state.desc.commandQueue = NULL;
    }

    if (slg_d3d12_state.desc.device) {
        slg_d3d12_state.desc.device->lpVtbl->Release(slg_d3d12_state.desc.device);
        slg_d3d12_state.desc.device = NULL;
    }
}


void _slg_d3d12_destroy_framebuffer(void) {
    slg_framebuffer_t* framebuffer = &slg_d3d12_state.frame_buf;

    if (framebuffer->depthStencilHeap) {
        framebuffer->depthStencilHeap->lpVtbl->Release(framebuffer->depthStencilHeap);
        framebuffer->depthStencilHeap = NULL;
    }
    /*if(framebuffer->depthTarget){
        framebuffer->depthTarget->lpVtbl->Release(framebuffer->depthTarget);
        framebuffer->depthStencilHeap = NULL;
    }*/
    for (unsigned int i = 0; i < FrameCount; i++) {
        if (framebuffer->frame_context[i].renderTarget) {
            framebuffer->frame_context[i].renderTarget->lpVtbl->Release(framebuffer->frame_context[i].renderTarget);
            framebuffer->frame_context[i].renderTarget = NULL;
        }
    }
    if (framebuffer->rtvHeap) {
        framebuffer->rtvHeap->lpVtbl->Release(framebuffer->rtvHeap);
        framebuffer->rtvHeap = NULL;
    }
    if (framebuffer->swapchain) {
        framebuffer->swapchain->lpVtbl->Release(framebuffer->swapchain);
        framebuffer->swapchain = NULL;
    }

    framebuffer->depthStencilDescriptorSize = 0; 
    framebuffer->rtvDescriptorSize = 0;
}

void _slg_d3d12_destroy_fence(void) {
    slg_fence_t* fence = &slg_d3d12_state.fence;

    if (fence->fence) {
        fence->fence->lpVtbl->Release(fence->fence);
        fence->fence = NULL;
    }

    if (fence->fenceEvent) {
        CloseHandle(fence->fenceEvent);
        fence->fenceEvent = NULL;
    }

    //fence->frameIndex = 0;
}

static void _slg_d3d12_destroy_shader_pool(Pool *shader_pool){
    size_t num_chunks = shader_pool->buffer_length/shader_pool->chunk_size;

    for(int i =0;i<num_chunks;i++){
        void* ptr = &shader_pool->buffer[i*shader_pool->chunk_size];
        if(pool_is_chunk_allocated(shader_pool, ptr)){
            slg_shader shd; 
            shd.shader_ptr = (slg_shader_t*)ptr;
            if(shd.shader_ptr->PixelShaderBlob){
                shd.shader_ptr->PixelShaderBlob->lpVtbl->Release(shd.shader_ptr->PixelShaderBlob);
                shd.shader_ptr->PixelShaderBlob = NULL;
            }
            if(shd.shader_ptr->VertexShaderBlob){
                shd.shader_ptr->VertexShaderBlob->lpVtbl->Release(shd.shader_ptr->VertexShaderBlob);
                shd.shader_ptr->VertexShaderBlob = NULL;
            }

            /*for(unsigned int t = 0;t<shd.shader_ptr->num_constant_buffers;t++){
                if(shd.shader_ptr->constantBuffers[t]!=NULL){
                    shd.shader_ptr->constantBuffers[t]->lpVtbl->Release(shd.shader_ptr->constantBuffers[t]);
                    shd.shader_ptr->constantBuffers[t] = NULL;
                }
            }*/
        }
    }
}

static void _slg_d3d12_destroy_pipeline_pool(Pool *pipeline_pool){
    size_t num_chunks = pipeline_pool->buffer_length/pipeline_pool->chunk_size;

    for(int i =0;i<num_chunks;i++){
        void* ptr = &pipeline_pool->buffer[i*pipeline_pool->chunk_size];
        if(pool_is_chunk_allocated(pipeline_pool, ptr)){
            
            slg_pipeline pip; 
            pip.data_ptr = (slg_pipeline_t*)ptr;
            if(pip.data_ptr->pipeline_state){
                pip.data_ptr->pipeline_state->lpVtbl->Release(pip.data_ptr->pipeline_state);
                pip.data_ptr->pipeline_state = NULL;
            }
            if(pip.data_ptr->root_signature){
                pip.data_ptr->root_signature->lpVtbl->Release(pip.data_ptr->root_signature);
                pip.data_ptr->root_signature = NULL;
            }
        }
    }
}

static void _slg_d3d12_destroy_buffer_pool(Pool *buffer_pool){
    size_t num_chunks = buffer_pool->buffer_length/buffer_pool->chunk_size;
    for(int i =0;i<num_chunks;i++){
        void* ptr = &buffer_pool->buffer[i*buffer_pool->chunk_size];
        if(pool_is_chunk_allocated(buffer_pool, ptr)){
            
            slg_buffer buf;
            buf.data_ptr = (slg_buffer_t*)ptr;
            if(buf.data_ptr->buffer){
                buf.data_ptr->buffer->lpVtbl->Release(buf.data_ptr->buffer);
                buf.data_ptr->buffer = NULL;
            }
        }
    }
}

static void _slg_d3d12_destroy_heap_pool(Pool *heap_pool){
    size_t num_chunks = heap_pool->buffer_length/heap_pool->chunk_size;
    for(int i = 0;i<num_chunks;i++){
        void* ptr = &heap_pool->buffer[i*heap_pool->chunk_size];
        if(pool_is_chunk_allocated(heap_pool,ptr)){
            slg_heap heap;
            heap.data_ptr = (slg_heap_t*)ptr;
            if(heap.data_ptr->heap){
                heap.data_ptr->heap->lpVtbl->Release(heap.data_ptr->heap);
                heap.data_ptr->heap = NULL;
            }
        }
    }
}

static void _slg_d3d12_destroy_texture_pool(Pool* texture_pool){
    size_t num_chunks = texture_pool->buffer_length/texture_pool->chunk_size;
    for(int i = 0;i<num_chunks;i++){
        void* ptr = &texture_pool->buffer[i*texture_pool->chunk_size];
        if(pool_is_chunk_allocated(texture_pool,ptr)){
            slg_texture texture;
            texture.data_ptr = (slg_texture_t*)ptr;
            if(texture.data_ptr->texture){
                texture.data_ptr->texture->lpVtbl->Release(texture.data_ptr->texture);
                texture.data_ptr->texture = NULL;
            }
        }
    }
}

//We have to free the backing buffers for the pools
static void slg_release_pool_memory(){
    free(slg_pools.bindingPoolBackingBuffer);
    free(slg_pools.bufferPoolBackingBuffer);
    free(slg_pools.pipelinePoolBackingBuffer);
    free(slg_pools.shaderPoolBackingBuffer);
    free(slg_pools.heapPoolBackingBuffer);
    free(slg_pools.texturePoolBackingBuffer);
}

void slg_cleanup(){
    #ifdef SLG_D3D12
    d3d12_waitForGPU();
    _slg_d3d12_destroy_desc();
    _slg_d3d12_destroy_fence();
    _slg_d3d12_destroy_framebuffer();
    _slg_d3d12_destroy_shader_pool(&slg_pools.shader_pool);
    _slg_d3d12_destroy_pipeline_pool(&slg_pools.pipeline_pool);
    _slg_d3d12_destroy_buffer_pool(&slg_pools.buffer_pool);
    _slg_d3d12_destroy_heap_pool(&slg_pools.heap_pool);
    _slg_d3d12_destroy_texture_pool(&slg_pools.texture_pool);
    #endif
    slg_release_pool_memory(); 
}







#endif