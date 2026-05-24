#include "jx_uart_send.h"

// 串口通信消息头
const unsigned char g_uart_send_head[] = {
  0xaa, 0x55
};

// 串口通信消息尾
const unsigned char g_uart_send_foot[] = {
  0x55, 0xaa
};

// 串口发送函数实现
void _uart_send_impl(unsigned char* buff, int len) {
  // TODO: 调用项目实际的串口发送函数
  /*
  int i = 0;
  unsigned char c;
  for (i = 0; i < len; i++) {
    c = buff[i];
    printf("%02X ", c);
  }
  printf("\n");
  */
}

// action: AA
void _uart_AA(unsigned char A1) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AA;
  param.d_uchar = A1;
  buff[3] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 4] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 6);
}

// action: AB
void _uart_AB(unsigned char A2) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AB;
  param.d_uchar = A2;
  buff[3] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 4] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 6);
}

// action: AC
void _uart_AC(unsigned char A3) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AC;
  param.d_uchar = A3;
  buff[3] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 4] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 6);
}

// action: AD
void _uart_AD(unsigned char A41, unsigned char A42) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AD;
  param.d_uchar = A41;
  buff[3] = param.d_uchar;
  param.d_uchar = A42;
  buff[4] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 5] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 7);
}

// action: BH
void _uart_BH(unsigned char A51, unsigned char A52, unsigned char A53) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_BH;
  param.d_uchar = A51;
  buff[3] = param.d_uchar;
  param.d_uchar = A52;
  buff[4] = param.d_uchar;
  param.d_uchar = A53;
  buff[5] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 6] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 8);
}

// action: AE
void _uart_AE() {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AE;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 3] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 5);
}

// action: AF
void _uart_AF(unsigned char A3) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AF;
  param.d_uchar = A3;
  buff[3] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 4] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 6);
}

// action: AG
void _uart_AG(unsigned char A3) {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AG;
  param.d_uchar = A3;
  buff[3] = param.d_uchar;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 4] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 6);
}

// action: AH
void _uart_AH() {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_AH;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 3] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 5);
}

// action: BC
void _uart_BC() {
  uart_param_t param;
  int i = 0;
  unsigned char buff[UART_SEND_MAX] = {0};
  for (i = 0; i < UART_MSG_HEAD_LEN; i++) {
      buff[i + 0] = g_uart_send_head[i];
  }
  buff[2] = U_MSG_BC;
  for (i = 0; i < UART_MSG_FOOT_LEN; i++) {
      buff[i + 3] = g_uart_send_foot[i];
  }
  _uart_send_impl(buff, 5);
}

