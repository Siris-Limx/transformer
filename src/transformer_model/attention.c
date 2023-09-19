#include <stdio.h>
#include "common/matmul.h"
#include "common/transpose.h"
#include "common/softmax.h"
#include "transformer_model/attention.h"

void attention() {
    // input initialization
    int seq_len = 10;
    int embed_dim = 4;
    int kqv_dim = 3;
    int scale = 2;
    int embed[seq_len][embed_dim];
    for (int i = 0; i < seq_len; i++) {
        for (int j = 0; j < embed_dim; j++) {
            embed[i][j] = i + j + 1;
        }
    }

    // K, Q, V initialization
    int mat_k[embed_dim][kqv_dim];
    int mat_q[embed_dim][kqv_dim];
    int mat_v[embed_dim][kqv_dim];
    for (int i = 0; i < embed_dim; i++) {
        for (int j = 0; j < kqv_dim; j++) {
            mat_k[i][j] = i + j + 1;
            mat_q[i][j] = i + j + 1;
            mat_v[i][j] = i + j + 1;
        }
    }

    // calculate K, Q, V
    int key[seq_len][kqv_dim];
    int query[seq_len][kqv_dim];
    int value[seq_len][kqv_dim];
    matmul(embed, mat_k, key, seq_len, embed_dim, kqv_dim);
    matmul(embed, mat_q, query, seq_len, embed_dim, kqv_dim);
    matmul(embed, mat_v, value, seq_len, embed_dim, kqv_dim);

    for (int i = 0; i < seq_len; i++)
    {
        for (int j = 0; j < kqv_dim; j++)
            printf("%d ", key[i][j]);
        printf("\n");
    }
    printf("\n");

    // Attention
    int mat_kq[seq_len][seq_len];
    int k_trans[kqv_dim][seq_len];
    int mat_kq_softmax[seq_len][seq_len];
    int mat_out[seq_len][kqv_dim];
    transpose(key, k_trans, seq_len, kqv_dim);
    matmul(query, k_trans, mat_kq, seq_len, kqv_dim, seq_len);
    for (int i = 0; i < seq_len; i++)
        for (int j = 0; j < seq_len; j++)
            mat_kq[i][j] = mat_kq[i][j] / scale;
    softmax(mat_kq, mat_kq_softmax, seq_len, seq_len);
    matmul(mat_kq, value, mat_out, seq_len, seq_len, kqv_dim);
}