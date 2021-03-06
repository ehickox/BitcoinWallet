#include "pebble.h"

static Window *window;
static Layer *layer;
static GBitmap *image;

static void layer_update_callback(Layer *me, GContext* ctx){

    GRect bounds = image->bounds;
    graphics_draw_bitmap_in_rect(ctx, image, (GRect) { .origin = {5, 5}, .size = bounds.size});
    graphics_draw_bitmap_in_rect(ctx, image, (GRect) { .origin = {140, 140}, .size = bounds.size});

}

int main(void){
    window = window_create();
    window_set_background_color(window, GColorBlack);
    window_stack_push(window, true);

    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_frame(window_layer);
    layer = layer_create(bounds);
    layer_set_update_proc(layer, layer_update_callback);
    layer_add_child(window_layer, layer);

    image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_WALLET);

    app_event_loop();

    gbitmap_destroy(image);
    
    window_destroy(window);
    layer_destroy(layer);
}
