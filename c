def selective_repeat_sender(frames, window_size):
    n = len(frames)
    acked = [False] * n
    base = 0

    while not all(acked):
        print("\nCurrent window:", end=' ')
        for i in range(base, min(base + window_size, n)):
            if not acked[i]:
                print(f"[{i}:{frames[i]}]", end=' ')
        print()
        
        # Transmit un-ACKed frames in the window
        for i in range(base, min(base + window_size, n)):
            if not acked[i]:
                print(f"Sent frame {i}: {frames[i]}")

        # User marks which frames in window were correctly ACKed
        user_input = input("Enter ACKed frame numbers (comma separated), leave blank if none: ")
        if user_input.strip().lower() == "done":
            print("Terminated by user.")
            break
        if user_input.strip():
            ack_numbers = [int(x) for x in user_input.split(',') if x.strip().isdigit()]
            for ack_no in ack_numbers:
                if 0 <= ack_no < n:
                    acked[ack_no] = True

        # Slide window forward to next unacked
        while base < n and acked[base]:
            base += 1

    print("\nAll frames sent and acknowledged (Selective Repeat ARQ simulation complete).")

# Example test frames and window
frames = ['A', 'B', 'C', 'D', 'E', 'F']
window_size = 3

selective_repeat_sender(frames, window_size)