// Copyright <2017> [Tim Hu]

class pixel;

void _blit(pixel *dst, const pixel *src, size_t s);
// 复制一块连续内存

void _blit_mask(pixel *dst, const pixel *src, size_t s);
// 处理透明色, 如果一个pixel的颜色是mask_color



class pixel {};

void _blit(pixel *dst, const pixel *src, size_t s) {
  // 复制一块连续内存
  for (size_t i = s; i != 0; --i; ++dst ; ++src)
    *dst = *src;
}


void _blit_mask(pixel *dst, const pixel *src, size_t s) {
  // 处理透明色, 如果一个pixel的颜色是mask_color
  for (size_t i = s; i != 0; --i; ++dst ; ++src) {
    if (*src != mask_color)
      *dst = *src;
  }
}

// 合二为一

void _blit(pixel *dst, const pixel *src, size_t s, bool mask_blit) {
  // 处理透明色, 如果一个pixel的颜色是mask_color
  // 循环内部增加一个判断，而条件分支又最影响现代CPU的效率
  for (size_t i = s; i != 0; --i; ++dst ; ++src) {
    if ((!mask_blit) || (*src != mask_color))
      *dst = *src;
  }
}

// 考虑使用模板, 拆分成两个函数
template <bool mask_blit>
void _blit(pixel *dst, const pixel *src, size_t s) {
  // 处理透明色, 如果一个pixel的颜色是mask_color
  // 循环内部增加一个判断，而条件分支又最影响现代CPU的效率
  for (size_t i = s; i != 0; --i; ++dst ; ++src) {
    if ((!mask_blit) || (*src != mask_color))
      *dst = *src;
  }
}

// 方便时候再封装一次

void blit(pixel *dst, const pixel *src, size_t s) {
  // 复制一块连续内存
  _blit<false>(dst, src, s);
}

void _blit_mask(pixel *dst, const pixel *src, size_t s) {
  // 处理透明色, 如果一个pixel的颜色是mask_color
  _blit<true>(dst, src, s);
}

// mask_blit作为模板参数，在编译期完成，不消耗运行时间。



int main() {
  return 0;
}
