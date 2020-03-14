Relay module function:
 v0.0.4
def @main(%x: int64) -> int64 {
  add(%x, 1 /* ty=int64 */) /* ty=int64 */
}

TVM graph:
 {
  "nodes": [
    {
      "op": "null", 
      "name": "x", 
      "inputs": []
    }, 
    {
      "op": "tvm_op", 
      "name": "fused_add", 
      "attrs": {
        "num_outputs": "1", 
        "num_inputs": "1", 
        "func_name": "fused_add", 
        "flatten_data": "0"
      }, 
      "inputs": [
        [
          0, 
          0, 
          0
        ]
      ]
    }
  ], 
  "arg_nodes": [0], 
  "heads": [
    [
      1, 
      0, 
      0
    ]
  ], 
  "attrs": {
    "dltype": [
      "list_str", 
      [
        "int64", 
        "int64"
      ]
    ], 
    "shape": [
      "list_shape", 
      [
        [], 
        []
      ]
    ], 
    "storage_id": [
      "list_int", 
      [0, 1]
    ]
  }, 
  "node_row_ptr": [0, 1, 2]
}
TVM parameters:
 {}
TVM compiled target function:
 ; ModuleID = 'fused_add'
source_filename = "fused_add"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%0 = type { i8*, %1, i32, %2, i64*, i64*, i64 }
%1 = type { i32, i32 }
%2 = type { i8, i8, i16 }

@__TVMAPISetLastError = linkonce dllexport local_unnamed_addr global void (i8*)* null, align 8
@.str = private constant [62 x i8] c"Assert fail: (num_args == 2), fused_add: num_args should be 2\00", align 1
@.str.1 = private constant [137 x i8] c"Assert fail: ((((arg0.code == 3) || (arg0.code == 13)) || (arg0.code == 7)) || (arg0.code == 4)), fused_add: Expect arg[0] to be pointer\00", align 1
@.str.2 = private constant [137 x i8] c"Assert fail: ((((arg1.code == 3) || (arg1.code == 13)) || (arg1.code == 7)) || (arg1.code == 4)), fused_add: Expect arg[1] to be pointer\00", align 1
@.str.3 = private constant [55 x i8] c"Assert fail: (dev_type == 1), device_type need to be 1\00", align 1
@.str.4 = private constant [81 x i8] c"Assert fail: (0 == tvm_struct_get(arg0, 0, 4)), arg0.ndim is expected to equal 0\00", align 1
@.str.5 = private constant [184 x i8] c"Assert fail: (((tvm_struct_get(arg0, 0, 5) == (uint8)0) && (tvm_struct_get(arg0, 0, 6) == (uint8)64)) && (tvm_struct_get(arg0, 0, 7) == (uint16)1)), arg0.dtype is expected to be int64\00", align 1
@.str.6 = private constant [112 x i8] c"Assert fail: ((uint64)0 == tvm_struct_get(arg0, 0, 8)), Argument arg0.byte_offset has an unsatisfied constraint\00", align 1
@.str.7 = private constant [81 x i8] c"Assert fail: (0 == tvm_struct_get(arg1, 0, 4)), arg1.ndim is expected to equal 0\00", align 1
@.str.8 = private constant [184 x i8] c"Assert fail: (((tvm_struct_get(arg1, 0, 5) == (uint8)0) && (tvm_struct_get(arg1, 0, 6) == (uint8)64)) && (tvm_struct_get(arg1, 0, 7) == (uint16)1)), arg1.dtype is expected to be int64\00", align 1
@.str.9 = private constant [112 x i8] c"Assert fail: ((uint64)0 == tvm_struct_get(arg1, 0, 8)), Argument arg1.byte_offset has an unsatisfied constraint\00", align 1
@.str.10 = private constant [105 x i8] c"Assert fail: (1 == tvm_struct_get(arg1, 0, 10)), Argument arg1.device_type has an unsatisfied constraint\00", align 1
@.str.11 = private constant [107 x i8] c"Assert fail: (dev_id == tvm_struct_get(arg1, 0, 9)), Argument arg1.device_id has an unsatisfied constraint\00", align 1
@__tvm_main__ = weak local_unnamed_addr constant [10 x i8] c"fused_add\00", align 1

define dllexport i32 @fused_add(i8* noalias nocapture readonly, i8* noalias nocapture readonly, i32) local_unnamed_addr {
entry:
  %3 = icmp eq i32 %2, 2
  br i1 %3, label %assert_end, label %assert_fail, !prof !5

assert_fail:                                      ; preds = %entry
  %4 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %4(i8* getelementptr inbounds ([62 x i8], [62 x i8]* @.str, i64 0, i64 0))
  ret i32 -1

assert_end:                                       ; preds = %entry
  %5 = bitcast i8* %0 to %0**
  %6 = load %0*, %0** %5, align 8
  %7 = bitcast i8* %1 to i32*
  %8 = load i32, i32* %7, align 4, !tbaa !9
  %9 = getelementptr inbounds i8, i8* %0, i64 8
  %10 = bitcast i8* %9 to %0**
  %11 = load %0*, %0** %10, align 8
  %12 = getelementptr inbounds %0, %0* %6, i64 0, i32 0
  %13 = load i8*, i8** %12, align 8
  %14 = getelementptr inbounds %0, %0* %6, i64 0, i32 1, i32 0
  %15 = load i32, i32* %14, align 4
  %16 = getelementptr inbounds %0, %0* %6, i64 0, i32 1, i32 1
  %17 = load i32, i32* %16, align 4
  %18 = getelementptr inbounds %0, %0* %11, i64 0, i32 0
  %19 = load i8*, i8** %18, align 8
  switch i32 %8, label %assert_fail1 [
    i32 13, label %assert_end2
    i32 7, label %assert_end2
    i32 4, label %assert_end2
    i32 3, label %assert_end2
  ]

assert_fail1:                                     ; preds = %assert_end
  %20 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %20(i8* getelementptr inbounds ([137 x i8], [137 x i8]* @.str.1, i64 0, i64 0))
  ret i32 -1

assert_end2:                                      ; preds = %assert_end, %assert_end, %assert_end, %assert_end
  %21 = getelementptr inbounds i8, i8* %1, i64 4
  %22 = bitcast i8* %21 to i32*
  %23 = load i32, i32* %22, align 4, !tbaa !23
  switch i32 %23, label %assert_fail3 [
    i32 13, label %assert_end4
    i32 7, label %assert_end4
    i32 4, label %assert_end4
    i32 3, label %assert_end4
  ]

assert_fail3:                                     ; preds = %assert_end2
  %24 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %24(i8* getelementptr inbounds ([137 x i8], [137 x i8]* @.str.2, i64 0, i64 0))
  ret i32 -1

assert_end4:                                      ; preds = %assert_end2, %assert_end2, %assert_end2, %assert_end2
  %25 = icmp eq i32 %15, 1
  br i1 %25, label %assert_end6, label %assert_fail5, !prof !5

assert_fail5:                                     ; preds = %assert_end4
  %26 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %26(i8* getelementptr inbounds ([55 x i8], [55 x i8]* @.str.3, i64 0, i64 0))
  ret i32 -1

assert_end6:                                      ; preds = %assert_end4
  %27 = getelementptr inbounds %0, %0* %6, i64 0, i32 2
  %28 = load i32, i32* %27, align 4
  %29 = icmp eq i32 %28, 0
  br i1 %29, label %assert_end8, label %assert_fail7, !prof !5

assert_fail7:                                     ; preds = %assert_end6
  %30 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %30(i8* getelementptr inbounds ([81 x i8], [81 x i8]* @.str.4, i64 0, i64 0))
  ret i32 -1

assert_end8:                                      ; preds = %assert_end6
  %31 = getelementptr inbounds %0, %0* %6, i64 0, i32 3, i32 2
  %32 = load i16, i16* %31, align 2
  %33 = icmp eq i16 %32, 1
  %34 = getelementptr inbounds %0, %0* %6, i64 0, i32 3, i32 1
  %35 = load i8, i8* %34, align 1
  %36 = icmp eq i8 %35, 64
  %37 = getelementptr inbounds %0, %0* %6, i64 0, i32 3, i32 0
  %38 = load i8, i8* %37, align 1
  %39 = icmp eq i8 %38, 0
  %40 = and i1 %36, %39
  %41 = and i1 %33, %40
  br i1 %41, label %assert_end10, label %assert_fail9, !prof !5

assert_fail9:                                     ; preds = %assert_end8
  %42 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %42(i8* getelementptr inbounds ([184 x i8], [184 x i8]* @.str.5, i64 0, i64 0))
  ret i32 -1

assert_end10:                                     ; preds = %assert_end8
  %43 = getelementptr inbounds %0, %0* %6, i64 0, i32 6
  %44 = load i64, i64* %43, align 8
  %45 = icmp eq i64 %44, 0
  br i1 %45, label %assert_end12, label %assert_fail11, !prof !5

assert_fail11:                                    ; preds = %assert_end10
  %46 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %46(i8* getelementptr inbounds ([112 x i8], [112 x i8]* @.str.6, i64 0, i64 0))
  ret i32 -1

assert_end12:                                     ; preds = %assert_end10
  %47 = getelementptr inbounds %0, %0* %11, i64 0, i32 2
  %48 = load i32, i32* %47, align 4
  %49 = icmp eq i32 %48, 0
  br i1 %49, label %assert_end14, label %assert_fail13, !prof !5

assert_fail13:                                    ; preds = %assert_end12
  %50 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %50(i8* getelementptr inbounds ([81 x i8], [81 x i8]* @.str.7, i64 0, i64 0))
  ret i32 -1

assert_end14:                                     ; preds = %assert_end12
  %51 = getelementptr inbounds %0, %0* %11, i64 0, i32 3, i32 2
  %52 = load i16, i16* %51, align 2
  %53 = icmp eq i16 %52, 1
  %54 = getelementptr inbounds %0, %0* %11, i64 0, i32 3, i32 1
  %55 = load i8, i8* %54, align 1
  %56 = icmp eq i8 %55, 64
  %57 = getelementptr inbounds %0, %0* %11, i64 0, i32 3, i32 0
  %58 = load i8, i8* %57, align 1
  %59 = icmp eq i8 %58, 0
  %60 = and i1 %56, %59
  %61 = and i1 %53, %60
  br i1 %61, label %assert_end16, label %assert_fail15, !prof !5

assert_fail15:                                    ; preds = %assert_end14
  %62 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %62(i8* getelementptr inbounds ([184 x i8], [184 x i8]* @.str.8, i64 0, i64 0))
  ret i32 -1

assert_end16:                                     ; preds = %assert_end14
  %63 = getelementptr inbounds %0, %0* %11, i64 0, i32 6
  %64 = load i64, i64* %63, align 8
  %65 = icmp eq i64 %64, 0
  br i1 %65, label %assert_end18, label %assert_fail17, !prof !5

assert_fail17:                                    ; preds = %assert_end16
  %66 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %66(i8* getelementptr inbounds ([112 x i8], [112 x i8]* @.str.9, i64 0, i64 0))
  ret i32 -1

assert_end18:                                     ; preds = %assert_end16
  %67 = getelementptr inbounds %0, %0* %11, i64 0, i32 1, i32 0
  %68 = load i32, i32* %67, align 4
  %69 = icmp eq i32 %68, 1
  br i1 %69, label %assert_end20, label %assert_fail19, !prof !5

assert_fail19:                                    ; preds = %assert_end18
  %70 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %70(i8* getelementptr inbounds ([105 x i8], [105 x i8]* @.str.10, i64 0, i64 0))
  ret i32 -1

assert_end20:                                     ; preds = %assert_end18
  %71 = getelementptr inbounds %0, %0* %11, i64 0, i32 1, i32 1
  %72 = load i32, i32* %71, align 4
  %73 = icmp eq i32 %17, %72
  br i1 %73, label %assert_end22, label %assert_fail21, !prof !5

assert_fail21:                                    ; preds = %assert_end20
  %74 = load void (i8*)*, void (i8*)** @__TVMAPISetLastError, align 8, !tbaa !6
  tail call void %74(i8* getelementptr inbounds ([107 x i8], [107 x i8]* @.str.11, i64 0, i64 0))
  ret i32 -1

assert_end22:                                     ; preds = %assert_end20
  tail call fastcc void @fused_add_compute_(i8* %19, i8* %13)
  ret i32 0
}

; Function Attrs: noinline norecurse nounwind
define private fastcc void @fused_add_compute_(i8* noalias nocapture, i8* noalias nocapture readonly) unnamed_addr #0 {
entry:
  %2 = bitcast i8* %1 to i64*
  %3 = load i64, i64* %2, align 64, !tbaa !25
  %4 = add nsw i64 %3, 1
  %5 = bitcast i8* %0 to i64*
  store i64 %4, i64* %5, align 64, !tbaa !39
  ret void
}

attributes #0 = { noinline norecurse nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4}

!0 = distinct !DICompileUnit(language: DW_LANG_C, file: !1, producer: "TVM", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, dwoId: 1)
!1 = !DIFile(filename: "model.tvm", directory: "/tmp/")
!2 = !{}
!3 = !{i32 2, !"tvm_target", !"llvm"}
!4 = !{i32 4, !"Debug Info Version", i32 3}
!5 = !{!"branch_weights", i32 1048576, i32 1}
!6 = !{!7, !7, i64 0}
!7 = !{!"ctx_ptr", !8, i64 0}
!8 = !{!"tvm-tbaa"}
!9 = !{!10, !10, i64 0}
!10 = !{!"0x55dbb95015b0.w1.b0", !11, i64 0}
!11 = !{!"0x55dbb95015b0.w2.b0", !12, i64 0}
!12 = !{!"0x55dbb95015b0.w4.b0", !13, i64 0}
!13 = !{!"0x55dbb95015b0.w8.b0", !14, i64 0}
!14 = !{!"0x55dbb95015b0.w16.b0", !15, i64 0}
!15 = !{!"0x55dbb95015b0.w32.b0", !16, i64 0}
!16 = !{!"0x55dbb95015b0.w64.b0", !17, i64 0}
!17 = !{!"0x55dbb95015b0.w128.b0", !18, i64 0}
!18 = !{!"0x55dbb95015b0.w256.b0", !19, i64 0}
!19 = !{!"0x55dbb95015b0.w512.b0", !20, i64 0}
!20 = !{!"0x55dbb95015b0.w1024.b0", !21, i64 0}
!21 = !{!"int32", !22, i64 0}
!22 = !{!"0x55dbb95015b0", !8, i64 0}
!23 = !{!24, !24, i64 0}
!24 = !{!"0x55dbb95015b0.w1.b1", !11, i64 0}
!25 = !{!26, !26, i64 0}
!26 = !{!"0x55dbb950e970.w1.b0", !27, i64 0}
!27 = !{!"0x55dbb950e970.w2.b0", !28, i64 0}
!28 = !{!"0x55dbb950e970.w4.b0", !29, i64 0}
!29 = !{!"0x55dbb950e970.w8.b0", !30, i64 0}
!30 = !{!"0x55dbb950e970.w16.b0", !31, i64 0}
!31 = !{!"0x55dbb950e970.w32.b0", !32, i64 0}
!32 = !{!"0x55dbb950e970.w64.b0", !33, i64 0}
!33 = !{!"0x55dbb950e970.w128.b0", !34, i64 0}
!34 = !{!"0x55dbb950e970.w256.b0", !35, i64 0}
!35 = !{!"0x55dbb950e970.w512.b0", !36, i64 0}
!36 = !{!"0x55dbb950e970.w1024.b0", !37, i64 0}
!37 = !{!"int64", !38, i64 0}
!38 = !{!"0x55dbb950e970", !8, i64 0}
!39 = !{!40, !40, i64 0}
!40 = !{!"0x55dbb95017d0.w1.b0", !41, i64 0}
!41 = !{!"0x55dbb95017d0.w2.b0", !42, i64 0}
!42 = !{!"0x55dbb95017d0.w4.b0", !43, i64 0}
!43 = !{!"0x55dbb95017d0.w8.b0", !44, i64 0}
!44 = !{!"0x55dbb95017d0.w16.b0", !45, i64 0}
!45 = !{!"0x55dbb95017d0.w32.b0", !46, i64 0}
!46 = !{!"0x55dbb95017d0.w64.b0", !47, i64 0}
!47 = !{!"0x55dbb95017d0.w128.b0", !48, i64 0}
!48 = !{!"0x55dbb95017d0.w256.b0", !49, i64 0}
!49 = !{!"0x55dbb95017d0.w512.b0", !50, i64 0}
!50 = !{!"0x55dbb95017d0.w1024.b0", !51, i64 0}
!51 = !{!"int64", !52, i64 0}
!52 = !{!"0x55dbb95017d0", !8, i64 0}

