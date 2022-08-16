//
// Created by wolves on 2022/8/16.
//
#include "stdlib.h"

/**
 * 有 n 个 (id, value) 对，其中 id 是 1 到 n 之间的一个整数，value 是一个字符串。不存在 id 相同的两个 (id, value) 对。

设计一个流，以 任意 顺序获取 n 个 (id, value) 对，并在多次调用时 按 id 递增的顺序 返回一些值。

实现 OrderedStream 类：

OrderedStream(int n) 构造一个能接收 n 个值的流，并将当前指针 ptr 设为 1 。
String[] insert(int id, String value) 向流中存储新的 (id, value) 对。存储后：
如果流存储有 id = ptr 的 (id, value) 对，则找出从 id = ptr 开始的 最长 id 连续递增序列 ，并 按顺序 返回与这些 id 关联的值的列表。然后，将 ptr 更新为最后那个  id + 1 。
否则，返回一个空列表。
 */

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, idKey, value, retSize);

 * orderedStreamFree(obj);
*/


typedef struct {
    int ptr;
    char **stream;
    int streamSize;
} OrderedStream;


OrderedStream *orderedStreamCreate(int n) {
    OrderedStream *obj = (OrderedStream *)malloc(sizeof(OrderedStream));
    obj->stream = (char **)malloc(sizeof(char *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        obj->stream[i] = NULL;
    }
    obj->streamSize = n + 1;
    obj->ptr = 1;
    return obj;
}

char **orderedStreamInsert(OrderedStream *obj, int idKey, char *value, int *retSize) {
    obj->stream[idKey] = value;
    char **res = (char **)malloc(sizeof(char *) * obj->streamSize);
    int pos = 0;
    while (obj->ptr < obj->streamSize && obj->stream[obj->ptr]) {
        res[pos++] = obj->stream[obj->ptr];
        obj->ptr++;
    }
    *retSize = pos;
    return res;
}

void orderedStreamFree(OrderedStream *obj) {
    free(obj->stream);
    free(obj);
}