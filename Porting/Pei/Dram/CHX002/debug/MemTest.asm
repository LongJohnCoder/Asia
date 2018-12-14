

 .686P
 .MODEL FLAT,C
 .CODE

StrError  db 'Error!Address= ', 00h
StrData   db ' Data=', 00h
StrBegin    db '---------8QUAD Memory Test Begin --------- ', 00h
StrEnd    db '--------- 8QUAD Memory Test End --------- ', 00h
StrCrossTest db 'Cross Rank Memory Test Begin', 00h
StrCrossBankTest db 'Cross Bank Memory Test Begin', 00h
StrNormalTest db 'Normal Memory Test Begin', 00h
StrEnter   db 0Dh, 0Ah, 00h
StrSpace   db ' ', 00h
StrTab	 db 09h, 00h

EndAddr equ 600000h
StartAddr equ 200000h
Pattern equ 0fefefefeh
UART_IO_BASE equ 3f8h

vCall	MACRO	register, procedure
	LOCAL	NextAddress
	mov	register, OFFSET NextAddress
	jmp	procedure
NextAddress:
ENDM



MemTest PROC PUBLIC
    pushad
    mov esp, offset StrBegin          
 vcall edi, OutputStringToComPort
    mov esp, offset StrEnter          
 vcall edi, OutputStringToComPort

 ;Output 80 Port = BB                                
     mov  al, 0BBh                       
     out  080h, al 

; Disable CPU Prefetch
 mov ecx, 1203h
 rdmsr
 bts eax, 27
 wrmsr

 
;Begin Cross  Bank Memtest
mov esp, offset StrCrossBankTest          
 vcall edi, OutputStringToComPort
mov esp, offset StrEnter          
 vcall edi, OutputStringToComPort  
        mov ebp, 0   
        
CrossBankTest:         
	mov esi, StartAddr
	add esi, ebp
CrossBankWriteLoop:
	mov dword ptr [esi], 0fefefefeh
	add esi, 08000h
	mov dword ptr [esi], 0fefefefeh
	add esi, 08000h
	mov dword ptr [esi], 001010101h
	add esi, 08000h
	mov dword ptr [esi], 001010101h
	add esi, 08000h
	mov dword ptr [esi], 0fdfdfdfdh
	add esi, 08000h
	mov dword ptr [esi], 0fdfdfdfdh
	add esi, 08000h
	mov dword ptr [esi], 002020202h
	add esi, 08000h
	mov dword ptr [esi], 002020202h
	add esi, 08000h
	mov ecx, EndAddr 
	cmp ecx, esi
	jnz CrossBankWriteLoop
	wbinvd                               ;Flush to DRAM
	
        mov esi, StartAddr
        add esi, ebp
CrossBankReadLoop:
        mov ebx, dword ptr [esi+08000h*0]        ;Read Data to cache,then check
	mov ebx, dword ptr [esi+08000h*1]
	mov ebx, dword ptr [esi+08000h*2]
	mov ebx, dword ptr [esi+08000h*3]
	mov ebx, dword ptr [esi+08000h*4]
	mov ebx, dword ptr [esi+08000h*5]
	mov ebx, dword ptr [esi+08000h*6]
	mov ebx, dword ptr [esi+08000h*7]
	

	
CrossBankCheckLoop:	
    cmp dword ptr [esi], 0fefefefeh
    jz CrossBankNoError1
    vcall ebx, ReportError
CrossBankNoError1:
    add esi, 08000h
    cmp dword ptr [esi], 0fefefefeh
    jz CrossBankNoError2
    vcall ebx, ReportError
CrossBankNoError2:
    add esi, 08000h
    cmp dword ptr [esi], 001010101h
    jz CrossBankNoError3
    vcall ebx, ReportError 
CrossBankNoError3:
    add esi, 08000h
    cmp dword ptr [esi], 001010101h
    jz CrossBankNoError4
    vcall ebx, ReportError
CrossBankNoError4:
    add esi, 08000h
    cmp dword ptr [esi], 0fdfdfdfdh
    jz CrossBankNoError5
    vcall ebx, ReportError
CrossBankNoError5:
    add esi, 08000h
    cmp dword ptr [esi], 0fdfdfdfdh
    jz CrossBankNoError6
    vcall ebx, ReportError
CrossBankNoError6:
    add esi, 08000h
    cmp dword ptr [esi], 002020202h
    jz CrossBankNoError7
    vcall ebx, ReportError
CrossBankNoError7:
    add esi, 08000h
    cmp dword ptr [esi], 002020202h
    jz CrossBankNoError8
    vcall ebx, ReportError
CrossBankNoError8:
    add esi, 08000h  
	
    mov ecx, EndAddr
    cmp esi, ecx
 ;if(esi< EndAddr),go on	
    jb CrossBankReadLoop                      

 ;Output 80 Port = BB                                
     mov  al, 0BCh                       
     out  080h, al 

     
    ;add ebp, 8 
    ;cmp ebp, 08000h
 ;if(ebp < 0800h), go to CrossBankTest   
    ;jb CrossBankTest
; Jump Bank Memtest  End


 mov esp, offset StrNormalTest          
 vcall edi, OutputStringToComPort
 mov esp, offset StrEnter          
 vcall edi, OutputStringToComPort      
;Nomal Memtest
	mov esi, StartAddr
WriteLoop:
	mov dword ptr [esi], 0fefefefeh
	add esi, 4
	mov dword ptr [esi], 0fefefefeh
	add esi, 4
	mov dword ptr [esi], 001010101h
	add esi, 4
	mov dword ptr [esi], 001010101h
	add esi, 4
	mov dword ptr [esi], 03c3c3c3ch
	add esi, 4
	mov dword ptr [esi], 03c3c3c3ch
	add esi, 4
	mov dword ptr [esi], 05a5a5a5ah
	add esi, 4
	mov dword ptr [esi], 05a5a5a5ah
	add esi, 4
	mov ecx, EndAddr 
	cmp ecx, esi
	jnz WriteLoop
	wbinvd                               ;Flush to DRAM



 ;Output 80 Port = BB                                
     mov  al, 0DDh                       
     out  080h, al 
	
    mov esi, StartAddr    
ReadLoop:
    mov ebx, dword ptr [esi+64*0]        ;Read Data to cache,then check
	mov ebx, dword ptr [esi+64*1]
	mov ebx, dword ptr [esi+64*2]
	mov ebx, dword ptr [esi+64*3]
	mov ebx, dword ptr [esi+64*4]
	mov ebx, dword ptr [esi+64*5]
	mov ebx, dword ptr [esi+64*6]
	mov ebx, dword ptr [esi+64*7]
	mov ebx, dword ptr [esi+64*8]
	mov ebx, dword ptr [esi+64*9]
	mov ebx, dword ptr [esi+64*10]
	mov ebx, dword ptr [esi+64*11]
	mov ebx, dword ptr [esi+64*12]

	mov bp, 26
CheckLoop:	
    cmp dword ptr [esi], 0fefefefeh
    jz NoError1
    vcall ebx, ReportError
NoError1:
    add esi, 4
    cmp dword ptr [esi], 0fefefefeh
    jz NoError2
    vcall ebx, ReportError
NoError2:
    add esi, 4
    cmp dword ptr [esi], 001010101h
    jz NoError3
    vcall ebx, ReportError 
NoError3:
    add esi, 4
    cmp dword ptr [esi], 001010101h
    jz NoError4
    vcall ebx, ReportError
NoError4:
    add esi, 4
    cmp dword ptr [esi], 03c3c3c3ch
    jz NoError5
    vcall ebx, ReportError
NoError5:
    add esi, 4
    cmp dword ptr [esi], 03c3c3c3ch
    jz NoError6
    vcall ebx, ReportError
NoError6:
    add esi, 4
    cmp dword ptr [esi], 05a5a5a5ah
    jz NoError7
    vcall ebx, ReportError
NoError7:
    add esi, 4
    cmp dword ptr [esi], 05a5a5a5ah
    jz NoError8
    vcall ebx, ReportError
NoError8:
    add esi, 4
	dec bp
	cmp bp,0
	jne Checkloop
	
	mov ecx, EndAddr+1-64*13
	cmp esi, ecx
 ;if(esi< EndAddr),go on	
    jb ReadLoop                      

; Normal test end


























;begin cross rank memory test    

	mov esp, offset StrCrossTest             ;Output string  cross rank memory test      
 vcall edi, OutputStringToComPort
        mov esp, offset StrEnter          
 vcall edi, OutputStringToComPort                                           
	mov esi, StartAddr
CrossWriteLoop:
	mov dword ptr [esi-20h], 0fefefefeh
	add esi, 4
	mov dword ptr [esi-20h], 0fefefefeh
	add esi, 4
	mov dword ptr [esi-20h], 001010101h
	add esi, 4
	mov dword ptr [esi-20h], 001010101h
	add esi, 4
	mov dword ptr [esi-20h], 0fdfdfdfdh
	add esi, 4
	mov dword ptr [esi-20h], 0fdfdfdfdh
	add esi, 4
	mov dword ptr [esi-20h], 002020202h
	add esi, 4
	mov dword ptr [esi-20h], 002020202h
	add esi, 4
	mov dword ptr [esi-20h], 0fbfbfbfbh
	add esi, 4
	mov dword ptr [esi-20h], 0fbfbfbfbh
	add esi, 4
	mov dword ptr [esi-20h], 004040404h
	add esi, 4
	mov dword ptr [esi-20h], 004040404h
	add esi, 4
	mov dword ptr [esi-20h], 0f7f7f7f7h
	add esi, 4
	mov dword ptr [esi-20h], 0f7f7f7f7h
	add esi, 4
	mov dword ptr [esi-20h], 008080808h
	add esi, 4
	mov dword ptr [esi-20h], 008080808h
	sub esi, 60
	add esi, 010000h
	mov ecx, EndAddr 
	cmp ecx, esi
	jnz CrossWriteLoop
	wbinvd                               ;Flush to DRAM


	
    mov esi, StartAddr
CrossReadLoop:
    mov ebx, dword ptr [esi+010000h*0-20h]        ;Read Data to cache,then check
	mov ebx, dword ptr [esi+010000h*1-20h]
	mov ebx, dword ptr [esi+010000h*2-20h]
	mov ebx, dword ptr [esi+010000h*3-20h]
	mov ebx, dword ptr [esi+010000h*4-20h]
	mov ebx, dword ptr [esi+010000h*5-20h]
	mov ebx, dword ptr [esi+010000h*6-20h]
	mov ebx, dword ptr [esi+010000h*7-20h]


	mov bp, 8
CrossCheckLoop:	
    cmp dword ptr [esi-20h], 0fefefefeh
    jz CrossNoError1
    vcall ebx, ReportError
CrossNoError1:
    add esi, 4
    cmp dword ptr [esi-20h], 0fefefefeh
    jz CrossNoError2
    vcall ebx, ReportError
CrossNoError2:
    add esi, 4
    cmp dword ptr [esi-20h], 001010101h
    jz CrossNoError3
    vcall ebx, ReportError 
CrossNoError3:
    add esi, 4
    cmp dword ptr [esi-20h], 001010101h
    jz CrossNoError4
    vcall ebx, ReportError
CrossNoError4:
    add esi, 4
    cmp dword ptr [esi-20h], 0fdfdfdfdh
    jz CrossNoError5
    vcall ebx, ReportError
CrossNoError5:
    add esi, 4
    cmp dword ptr [esi-20h], 0fdfdfdfdh
    jz CrossNoError6
    vcall ebx, ReportError
CrossNoError6:
    add esi, 4
    cmp dword ptr [esi-20h], 002020202h
    jz CrossNoError7
    vcall ebx, ReportError
CrossNoError7:
    add esi, 4
    cmp dword ptr [esi-20h], 002020202h
    jz CrossNoError8
    vcall ebx, ReportError
CrossNoError8:
    add esi, 4
    cmp dword ptr [esi-20h], 0fbfbfbfbh
    jz CrossNoError9
    vcall ebx, ReportError
CrossNoError9:
    add esi, 4
    cmp dword ptr [esi-20h], 0fbfbfbfbh
    jz CrossNoError10
    vcall ebx, ReportError
CrossNoError10:
    add esi, 4
    cmp dword ptr [esi-20h], 004040404h
    jz CrossNoError11
    vcall ebx, ReportError
CrossNoError11:
    add esi, 4
    cmp dword ptr [esi-20h], 004040404h
    jz CrossNoError12
    vcall ebx, ReportError
CrossNoError12:
    add esi, 4
    cmp dword ptr [esi-20h], 0f7f7f7f7h
    jz CrossNoError13
    vcall ebx, ReportError
CrossNoError13:
    add esi, 4
    cmp dword ptr [esi-20h], 0f7f7f7f7h
    jz CrossNoError14
    vcall ebx, ReportError
CrossNoError14:
    add esi, 4
    cmp dword ptr [esi-20h], 008080808h
    jz CrossNoError15
    vcall ebx, ReportError
CrossNoError15:
    add esi, 4
    cmp dword ptr [esi-20h], 008080808h
    jz CrossNoError16
    vcall ebx, ReportError
CrossNoError16:
    sub esi, 60
    add esi, 010000h
    dec bp
	cmp bp,0
	jne CrossCheckloop
	
	mov ecx, EndAddr
	cmp esi, ecx
    jb CrossReadLoop                       ;if(esi< EndAddr),go on

;End cross rank memory test     











	
	mov esp, offset StrEnd			   ;Output string  Memory test End		
	vcall edi, OutputStringToComPort
    jmp $                              ;Finish memory test,never return,hang here
    ret
MemTest	EndP





ReportError PROC PUBLIC                 ;Error Report
    mov	al, 0EEh
    out	080h, al                         ;Write Io port

    mov esp, offset StrError
 vcall edi, OutputStringToComPort
 
    mov eax, esi                         ;Output Error Address
    shr eax, 24
    and eax, 0ffh
    ;mov ecx, 4
 vcall edi, OutputValueToComPort
    mov eax, esi
    shr eax, 16
    and eax, 0ffh
    ;mov ecx, 4
 vcall edi, OutputValueToComPort
    mov eax, esi
    shr eax, 8
    and eax, 0ffh
    ;mov ecx, 4
 vcall edi, OutputValueToComPort
    mov eax, esi 
    and eax, 0ffh
    ;mov ecx, 4
 vcall edi, OutputValueToComPort

	
 
	mov esp, offset StrData
 vcall edi, OutputStringToComPort

	mov eax,[esi]                        ;Output Error Data
    shr eax, 24
    and eax, 0ffh
	mov ecx, 4
 vcall edi, OutPutValueToComport    
    mov eax, [esi]
    shr eax, 16
    and eax, 0ffh
    mov ecx, 4
 vcall edi, OutputValueToComPort
    mov eax, [esi]
    shr eax, 8
    and eax, 0ffh
    mov ecx, 4
 vcall edi, OutputValueToComPort
    mov eax, [esi]    
    and eax, 0ffh
    mov ecx, 4
 vcall edi, OutputValueToComPort

	

    mov esp, offset StrEnter
 vcall edi, OutputStringToComPort
	
    jmp ebx
    ;jmp $

ReportError EndP




	
OutputStringToComPort PROC PUBLIC         ;Output string to comport
    mov    dx, UART_IO_BASE
	
NextOne:
    mov    al, cs:[esp]
	cmp    al, 0
    je     EndofString
    out    dx, al
	add    dx, 5			   ; set to 3f8+5
WaitFiFoEmpty:
	in	   al, dx
	bt	   ax, 5			   ; bit[5] is zero?
	jnc    WaitFiFoEmpty
	sub    dx, 5 
	inc    esp
    jmp    NextOne

EndofString:
    jmp edi
OutputStringToComPort EndP



OutputValueToComPort PROC PUBLIC           ;output value to comport
    mov    dx, cx
    bswap  edx                   ; save cx in edx[31:16]
    
    mov    cl, al                ; save low nibble in cl
    and    cl, 0Fh    
    bts    cx, 7                 ; set bit7 as a flag
    mov    dx, UART_IO_BASE      ; set dx to 3f8

    and    al, 0F0h
    shr    al, 4                 ; shift high nibble in [3:0]

SendHighNible:
    cmp    al, 0Ah
    jae    OverA
    add    al, 030h
    jmp    Output2ComPort
OverA:
    add    al, (041h-00Ah)
Output2ComPort:
    out    dx, al              ; output to comport

    ; wait for fifo empty for next
    add    dx, 5               ; set to 3f8+5
WaitFiFoEmpty:
    in     al, dx
    bt     ax, 5               ; bit[5] is zero?
    jnc     WaitFiFoEmpty
    sub    dx, 5               ; set back to 3f8

    mov    al, cl              ; move low nible to al
    btr    cx, 7               ; clear flag
    btr    ax, 7               ; sent ?
    jc     SendHighNible

    bswap  edx                   ; restore cx
    mov    cx, dx

    jmp    edi
OutputValueToComPort EndP


    

END
