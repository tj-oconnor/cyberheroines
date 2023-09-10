PROGRAM DorothyVaughan
    CHARACTER(100) :: input_array
    CHARACTER(100) :: modified_array
    CHARACTER(100) :: final_array
    INTEGER :: i, ascii_value, length
    INTEGER :: unit, status

    ! Open the input file
    OPEN(unit, file='flag.txt', status='old', iostat=status)

    IF (status /= 0) THEN
        WRITE(*,*) "Error opening input file 'flag.txt'"
        STOP
    END IF

    ! Read the word from the file
    READ(unit, '(A)') input_array

    ! Close the input file
    CLOSE(unit)

    length = LEN_TRIM(input_array)

    ! Initialize the modified array
    modified_array = input_array

    DO i = 1, length
        IF (input_array(i:i) == '{' .OR. input_array(i:i) == '}') THEN
            modified_array(i:i) = input_array(i:i)
        ELSE
            ascii_value = ICHAR(input_array(i:i))
            IF (MOD(i, 2) == 0) THEN
                ascii_value = ascii_value + 3
            ELSE
                ascii_value = ascii_value + 7
            END IF
            modified_array(i:i) = CHAR(ascii_value)
        END IF
    END DO

    final_array = ""
    DO i = 1, length
        ascii_value = ICHAR(modified_array(i:i))
        IF (ascii_value >= ICHAR('A') .AND. ascii_value <= ICHAR('Z')) THEN
            final_array(i:i) = CHAR(MOD(ascii_value - ICHAR('A') + 18, 26) + ICHAR('A'))
        ELSE IF (ascii_value >= ICHAR('a') .AND. ascii_value <= ICHAR('z')) THEN
            final_array(i:i) = CHAR(MOD(ascii_value - ICHAR('a') + 18, 26) + ICHAR('a'))
        ELSE
            final_array(i:i) = modified_array(i:i)
        END IF
    END DO

    WRITE(*,*) "Final Array:", final_array(1:length)

END PROGRAM DorothyVaughan
