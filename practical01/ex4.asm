
ex4:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <putchar@plt>:
    1030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 4018 <putchar@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

0000000000001040 <__errno_location@plt>:
    1040:	ff 25 da 2f 00 00    	jmpq   *0x2fda(%rip)        # 4020 <__errno_location@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <.plt>

0000000000001050 <printf@plt>:
    1050:	ff 25 d2 2f 00 00    	jmpq   *0x2fd2(%rip)        # 4028 <printf@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	pushq  $0x2
    105b:	e9 c0 ff ff ff       	jmpq   1020 <.plt>

0000000000001060 <read@plt>:
    1060:	ff 25 ca 2f 00 00    	jmpq   *0x2fca(%rip)        # 4030 <read@GLIBC_2.2.5>
    1066:	68 03 00 00 00       	pushq  $0x3
    106b:	e9 b0 ff ff ff       	jmpq   1020 <.plt>

0000000000001070 <fprintf@plt>:
    1070:	ff 25 c2 2f 00 00    	jmpq   *0x2fc2(%rip)        # 4038 <fprintf@GLIBC_2.2.5>
    1076:	68 04 00 00 00       	pushq  $0x4
    107b:	e9 a0 ff ff ff       	jmpq   1020 <.plt>

0000000000001080 <malloc@plt>:
    1080:	ff 25 ba 2f 00 00    	jmpq   *0x2fba(%rip)        # 4040 <malloc@GLIBC_2.2.5>
    1086:	68 05 00 00 00       	pushq  $0x5
    108b:	e9 90 ff ff ff       	jmpq   1020 <.plt>

0000000000001090 <open@plt>:
    1090:	ff 25 b2 2f 00 00    	jmpq   *0x2fb2(%rip)        # 4048 <open@GLIBC_2.2.5>
    1096:	68 06 00 00 00       	pushq  $0x6
    109b:	e9 80 ff ff ff       	jmpq   1020 <.plt>

00000000000010a0 <perror@plt>:
    10a0:	ff 25 aa 2f 00 00    	jmpq   *0x2faa(%rip)        # 4050 <perror@GLIBC_2.2.5>
    10a6:	68 07 00 00 00       	pushq  $0x7
    10ab:	e9 70 ff ff ff       	jmpq   1020 <.plt>

00000000000010b0 <atoi@plt>:
    10b0:	ff 25 a2 2f 00 00    	jmpq   *0x2fa2(%rip)        # 4058 <atoi@GLIBC_2.2.5>
    10b6:	68 08 00 00 00       	pushq  $0x8
    10bb:	e9 60 ff ff ff       	jmpq   1020 <.plt>

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	4c 8d 05 96 02 00 00 	lea    0x296(%rip),%r8        # 1370 <__libc_csu_fini>
    10da:	48 8d 0d 1f 02 00 00 	lea    0x21f(%rip),%rcx        # 1300 <__libc_csu_init>
    10e1:	48 8d 3d d1 00 00 00 	lea    0xd1(%rip),%rdi        # 11b9 <main>
    10e8:	ff 15 f2 2e 00 00    	callq  *0x2ef2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ee:	f4                   	hlt    
    10ef:	90                   	nop

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4070 <__TMC_END__>
    10f7:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4070 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 ce 2e 00 00 	mov    0x2ece(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmpq   *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4070 <__TMC_END__>
    1127:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4070 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 a5 2e 00 00 	mov    0x2ea5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmpq   *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d 1d 2f 00 00 00 	cmpb   $0x0,0x2f1d(%rip)        # 4088 <completed.0>
    116b:	75 33                	jne    11a0 <__do_global_dtors_aux+0x40>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 82 2e 00 00 	cmpq   $0x0,0x2e82(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0d                	je     1188 <__do_global_dtors_aux+0x28>
    117b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4068 <__dso_handle>
    1182:	ff 15 70 2e 00 00    	callq  *0x2e70(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1188:	e8 63 ff ff ff       	callq  10f0 <deregister_tm_clones>
    118d:	c6 05 f4 2e 00 00 01 	movb   $0x1,0x2ef4(%rip)        # 4088 <completed.0>
    1194:	5d                   	pop    %rbp
    1195:	c3                   	retq   
    1196:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    119d:	00 00 00 
    11a0:	c3                   	retq   
    11a1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    11a8:	00 00 00 00 
    11ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000011b0 <frame_dummy>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	e9 67 ff ff ff       	jmpq   1120 <register_tm_clones>

00000000000011b9 <main>:
    11b9:	55                   	push   %rbp
    11ba:	48 89 e5             	mov    %rsp,%rbp
    11bd:	48 83 ec 50          	sub    $0x50,%rsp
    11c1:	89 7d cc             	mov    %edi,-0x34(%rbp)
    11c4:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    11c8:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    11cc:	83 7d cc 03          	cmpl   $0x3,-0x34(%rbp)
    11d0:	74 1b                	je     11ed <main+0x34>
    11d2:	48 8d 3d 2b 0e 00 00 	lea    0xe2b(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    11d9:	b8 00 00 00 00       	mov    $0x0,%eax
    11de:	e8 6d fe ff ff       	callq  1050 <printf@plt>
    11e3:	b8 01 00 00 00       	mov    $0x1,%eax
    11e8:	e9 09 01 00 00       	jmpq   12f6 <main+0x13d>
    11ed:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    11f1:	48 83 c0 08          	add    $0x8,%rax
    11f5:	48 8b 00             	mov    (%rax),%rax
    11f8:	be 00 00 00 00       	mov    $0x0,%esi
    11fd:	48 89 c7             	mov    %rax,%rdi
    1200:	b8 00 00 00 00       	mov    $0x0,%eax
    1205:	e8 86 fe ff ff       	callq  1090 <open@plt>
    120a:	89 45 dc             	mov    %eax,-0x24(%rbp)
    120d:	83 7d dc ff          	cmpl   $0xffffffff,-0x24(%rbp)
    1211:	75 54                	jne    1267 <main+0xae>
    1213:	e8 28 fe ff ff       	callq  1040 <__errno_location@plt>
    1218:	8b 00                	mov    (%rax),%eax
    121a:	89 c6                	mov    %eax,%esi
    121c:	48 8d 3d ff 0d 00 00 	lea    0xdff(%rip),%rdi        # 2022 <_IO_stdin_used+0x22>
    1223:	b8 00 00 00 00       	mov    $0x0,%eax
    1228:	e8 23 fe ff ff       	callq  1050 <printf@plt>
    122d:	e8 0e fe ff ff       	callq  1040 <__errno_location@plt>
    1232:	8b 10                	mov    (%rax),%edx
    1234:	48 8b 05 45 2e 00 00 	mov    0x2e45(%rip),%rax        # 4080 <stderr@@GLIBC_2.2.5>
    123b:	48 8d 35 e0 0d 00 00 	lea    0xde0(%rip),%rsi        # 2022 <_IO_stdin_used+0x22>
    1242:	48 89 c7             	mov    %rax,%rdi
    1245:	b8 00 00 00 00       	mov    $0x0,%eax
    124a:	e8 21 fe ff ff       	callq  1070 <fprintf@plt>
    124f:	48 8d 3d dc 0d 00 00 	lea    0xddc(%rip),%rdi        # 2032 <_IO_stdin_used+0x32>
    1256:	e8 45 fe ff ff       	callq  10a0 <perror@plt>
    125b:	e8 e0 fd ff ff       	callq  1040 <__errno_location@plt>
    1260:	8b 00                	mov    (%rax),%eax
    1262:	e9 8f 00 00 00       	jmpq   12f6 <main+0x13d>
    1267:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    126b:	48 83 c0 10          	add    $0x10,%rax
    126f:	48 8b 00             	mov    (%rax),%rax
    1272:	48 89 c7             	mov    %rax,%rdi
    1275:	e8 36 fe ff ff       	callq  10b0 <atoi@plt>
    127a:	48 98                	cltq   
    127c:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1280:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1284:	89 c6                	mov    %eax,%esi
    1286:	48 8d 3d ab 0d 00 00 	lea    0xdab(%rip),%rdi        # 2038 <_IO_stdin_used+0x38>
    128d:	b8 00 00 00 00       	mov    $0x0,%eax
    1292:	e8 b9 fd ff ff       	callq  1050 <printf@plt>
    1297:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    129b:	48 89 c7             	mov    %rax,%rdi
    129e:	e8 dd fd ff ff       	callq  1080 <malloc@plt>
    12a3:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    12a7:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    12ab:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    12af:	8b 45 dc             	mov    -0x24(%rbp),%eax
    12b2:	48 89 ce             	mov    %rcx,%rsi
    12b5:	89 c7                	mov    %eax,%edi
    12b7:	e8 a4 fd ff ff       	callq  1060 <read@plt>
    12bc:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    12c0:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    12c7:	00 
    12c8:	eb 1d                	jmp    12e7 <main+0x12e>
    12ca:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    12ce:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    12d2:	48 01 d0             	add    %rdx,%rax
    12d5:	0f b6 00             	movzbl (%rax),%eax
    12d8:	0f be c0             	movsbl %al,%eax
    12db:	89 c7                	mov    %eax,%edi
    12dd:	e8 4e fd ff ff       	callq  1030 <putchar@plt>
    12e2:	48 83 45 e0 01       	addq   $0x1,-0x20(%rbp)
    12e7:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    12eb:	48 3b 45 f8          	cmp    -0x8(%rbp),%rax
    12ef:	72 d9                	jb     12ca <main+0x111>
    12f1:	b8 00 00 00 00       	mov    $0x0,%eax
    12f6:	c9                   	leaveq 
    12f7:	c3                   	retq   
    12f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    12ff:	00 

0000000000001300 <__libc_csu_init>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	41 57                	push   %r15
    1306:	4c 8d 3d db 2a 00 00 	lea    0x2adb(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    130d:	41 56                	push   %r14
    130f:	49 89 d6             	mov    %rdx,%r14
    1312:	41 55                	push   %r13
    1314:	49 89 f5             	mov    %rsi,%r13
    1317:	41 54                	push   %r12
    1319:	41 89 fc             	mov    %edi,%r12d
    131c:	55                   	push   %rbp
    131d:	48 8d 2d cc 2a 00 00 	lea    0x2acc(%rip),%rbp        # 3df0 <__do_global_dtors_aux_fini_array_entry>
    1324:	53                   	push   %rbx
    1325:	4c 29 fd             	sub    %r15,%rbp
    1328:	48 83 ec 08          	sub    $0x8,%rsp
    132c:	e8 cf fc ff ff       	callq  1000 <_init>
    1331:	48 c1 fd 03          	sar    $0x3,%rbp
    1335:	74 1f                	je     1356 <__libc_csu_init+0x56>
    1337:	31 db                	xor    %ebx,%ebx
    1339:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1340:	4c 89 f2             	mov    %r14,%rdx
    1343:	4c 89 ee             	mov    %r13,%rsi
    1346:	44 89 e7             	mov    %r12d,%edi
    1349:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    134d:	48 83 c3 01          	add    $0x1,%rbx
    1351:	48 39 dd             	cmp    %rbx,%rbp
    1354:	75 ea                	jne    1340 <__libc_csu_init+0x40>
    1356:	48 83 c4 08          	add    $0x8,%rsp
    135a:	5b                   	pop    %rbx
    135b:	5d                   	pop    %rbp
    135c:	41 5c                	pop    %r12
    135e:	41 5d                	pop    %r13
    1360:	41 5e                	pop    %r14
    1362:	41 5f                	pop    %r15
    1364:	c3                   	retq   
    1365:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    136c:	00 00 00 00 

0000000000001370 <__libc_csu_fini>:
    1370:	f3 0f 1e fa          	endbr64 
    1374:	c3                   	retq   

Disassembly of section .fini:

0000000000001378 <_fini>:
    1378:	f3 0f 1e fa          	endbr64 
    137c:	48 83 ec 08          	sub    $0x8,%rsp
    1380:	48 83 c4 08          	add    $0x8,%rsp
    1384:	c3                   	retq   
