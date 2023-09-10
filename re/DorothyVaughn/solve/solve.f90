PROGRAM ReverseDorothy
    CHARACTER(100) :: input_array
    CHARACTER(100) :: rot8_array
    CHARACTER(100) :: modified_array
    INTEGER :: i, ascii_value, length

    ! Prompt the user for input
    WRITE(*,*) "Enter a word or phrase:"
    READ(*, '(A)') input_array

    length = LEN_TRIM(input_array)

    ! Apply ROT8 encryption to the input array
    rot8_array = ""
    DO i = 1, length
        ascii_value = ICHAR(input_array(i:i))
        IF (ascii_value >= ICHAR('A') .AND. ascii_value <= ICHAR('Z')) THEN
            rot8_array(i:i) = CHAR(MOD(ascii_value - ICHAR('A') + 8, 26) + ICHAR('A'))
        ELSE IF (ascii_value >= ICHAR('a') .AND. ascii_value <= ICHAR('z')) THEN
            rot8_array(i:i) = CHAR(MOD(ascii_value - ICHAR('a') + 8, 26) + ICHAR('a'))
        ELSE
            rot8_array(i:i) = input_array(i:i)
        END IF
    END DO

    ! Subtract values based on even and odd array indices while ignoring curly brackets
    modified_array = ""
    DO i = 1, length
        IF (rot8_array(i:i) == '{' .OR. rot8_array(i:i) == '}') THEN
            modified_array(i:i) = rot8_array(i:i)
        ELSE
            ascii_value = ICHAR(rot8_array(i:i))
            IF (MOD(i, 2) == 0) THEN
                ascii_value = ascii_value - 3
            ELSE
                ascii_value = ascii_value - 7
            END IF
            modified_array(i:i) = CHAR(ascii_value)
        END IF
    END DO

    WRITE(*,*) "Final Result:", modified_array(1:length)

END PROGRAM ReverseDorothy
