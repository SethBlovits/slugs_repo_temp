
#include <windows.h>
#include <stdbool.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define APP_UTILITY_IMPLEMENTATION
#include "app_utility.h"
//#include <d3d12.h>
//#include <dxgi1_6.h>
//#include <d3dcompiler.h>
#define _DEBUG
#define SLUGS_IMPLEMENTATION
#define SLG_HOT_RELOADING
#include "slugs_graphics.h"
#define SLUGS_IMGUI_IMPLEMENTATION
#include "slugs_imgui.h"
#include "mathUtil.h"

typedef struct{
    Vector3 movevector;
    Vector3 position;
    Vector3 direction;
    Vector3 target;
    Vector3 up;
    Vector3 right;
    Mat4 view;
    Mat4 projection;
}Camera;
Camera mainCamera;

typedef struct Render_Window{
    int width;
    int height;
    const char* name;
    bool m_useWarpDevice;
}Render_Window;
const char g_szClassName[] = "myWindowClass";

typedef struct{
    Vector3 position;
    Vector4 color;
    Vector2 uv;
}Vertex;

//Forward Declarations
// 
// 
///void win32_InitD3D12();
// Step 4: the Window Procedure

//static IDXGIFactory4* s_factory = NULL;
/*LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //Render_Window* render_window = (Render_Window*)GetWindowLongPtr(hwnd,GWLP_USERDATA);
    switch(msg)
    {   
        case WM_CREATE:
        {
            LPCREATESTRUCT pCreateStruct = (LPCREATESTRUCT)lParam;
            SetWindowLongPtr(hwnd,GWLP_USERDATA,(LONG_PTR)pCreateStruct->lpCreateParams);
        }
        break;
        case WM_PAINT:
          
        break;
        case WM_LBUTTONDOWN:
            
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}*/




/*int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{

    hPrevInstance;
    lpCmdLine;
    
    uint8_t arena_backingBuffer[131072];
    arena_init(&slg_arena,arena_backingBuffer,131072);
    slg_arena.name = "main_arena";
    
    double time =0;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    LARGE_INTEGER last_time;
    QueryPerformanceCounter(&last_time);
    Render_Window render_window = {
        800,
        600,
        "window",
        false
    };


    //D3D12_Init(render_window);

    //synchronization_objects.m_frameIndex = 0;
    //pipeline_objects.m_viewport = {0.0f,0.0f,static_cast<float>(dx_window.width),static_cast<float>(dx_window.height)};
    //pipeline_objects.m_scissorRect = {0,0,static_cast<LONG>(dx_window.width),static_cast<LONG>(dx_window.height)};
    //pipeline_objects.m_rtvDescriptorSize = 0;

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW | WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, &render_window);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    
    slg_d3d12_state.appdata.width = 800;
    slg_d3d12_state.appdata.height = 600;
    slg_d3d12_state.appdata.name = "test app";
    slg_d3d12_state.appdata.hwnd = hwnd;

    slg_setup();

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    double delta_time = 0;

    slimgui_setup();
    while(true){

        //slg_check_for_hot_reload();
        slg_begin_frame();
        LARGE_INTEGER current_time;
        QueryPerformanceCounter(&current_time);

        delta_time = (double)(current_time.QuadPart-last_time.QuadPart)/frequency.QuadPart;
        time += delta_time;

        last_time = current_time;
        slg_begin_pass();
        slimgui_frame();

        
        if(PeekMessage(&Msg,NULL,0,0,PM_REMOVE)){
            if(Msg.message == WM_QUIT){
                break;
            }
            TranslateMessage(&Msg);
            DispatchMessage(&Msg); 
        }
        slimgui_end_frame();
    
    }
   
    slg_cleanup();
    return (int)Msg.wParam;
}*/

void init(){
    uint8_t arena_backingBuffer[131072];
    arena_init(&slg_arena,arena_backingBuffer,131072);
    slg_arena.name = "main_arena";
    slg_d3d12_state.appdata.width = 800;
    slg_d3d12_state.appdata.height = 600;
    slg_d3d12_state.appdata.name = "test app";
    slg_d3d12_state.appdata.hwnd = app_get_window_handle();
    slg_setup();
    slimgui_setup();
    slg_close_setup();
}
void frame(){
    app_get_cursor_pos(&slimgui_input_state.mouse_x,&slimgui_input_state.mouse_y);

    slg_begin_frame();
    slg_begin_pass();
    slimgui_frame();
    slimgui_end_frame();
}
void event(app_event_t* event){
    switch(event->event_code){
        case(APP_EVENT_MOUSE_LEFT_BUTTON_DOWN):{
            slimgui_input_state.left_mouse_down = true;
        }
        case(APP_EVENT_MOUSE_LEFT_BUTTON_UP):{
            slimgui_input_state.left_mouse_down = false;
        }
        case(APP_EVENT_MOUSE_RIGHT_BUTTON_DOWN):{
            slimgui_input_state.right_mouse_down = true;
        }
        case(APP_EVENT_MOUSE_RIGHT_BUTTON_UP):{
            slimgui_input_state.right_mouse_down = false;
        }

    }
}
void cleanup(){
    slg_cleanup();
}
int main(){
    app_init((app_desc_t){
        .frame_func = frame,
        .init_func = init,
        .cleanup_func = cleanup,
        .width = 800,
        .height = 600
    });
    app_mainline();

}


