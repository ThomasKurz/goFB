-- This file has been automatically generated by go-iec61499-vhdl and should not be edited by hand
-- Converter written by Hammond Pearce and available at github.com/kiwih/go-iec61499-vhdl

-- This file represents the Basic Function Block for CanisterCounter

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;



entity CanisterCounter is

	port(
		--for clock and reset signal
		clk		: in	std_logic;
		reset	: in	std_logic;
		enable	: in	std_logic;
		sync	: in	std_logic;
		
		--input events
		LasersChanged : in std_logic;
		
		
		--output events
		CanisterCountChanged : out std_logic;
		
		
		--input variables
		DoorSiteLaser_I : in std_logic; --type was BOOL
		RejectBinLaser_I : in std_logic; --type was BOOL
		AcceptBinLaser_I : in std_logic; --type was BOOL
		
		
		--output variables
		CanisterCount_O : out unsigned(7 downto 0); --type was BYTE
		
		
		--for done signal
		done : out std_logic
	);

end entity;


architecture rtl of CanisterCounter is
	-- Build an enumerated type for the state machine
	type state_type is (STATE_Start);

	-- Register to hold the current state
	signal state   : state_type := STATE_Start;

	-- signals to store variable sampled on enable 
	signal DoorSiteLaser : std_logic := '0'; --register for input
	signal RejectBinLaser : std_logic := '0'; --register for input
	signal AcceptBinLaser : std_logic := '0'; --register for input
	
	-- signals to rename outputs 
	signal CanisterCount : unsigned(7 downto 0) := (others => '0'); 
	

	-- signals for enabling algorithms	
	signal ChangeCount_alg_en : std_logic := '0'; 
	signal ChangeCount_alg_done : std_logic := '1';
	

	-- signal for algorithm completion
	signal AlgorithmsStart : std_logic := '0';
	signal AlgorithmsDone : std_logic;

	
begin
	-- Registers for data variables (only updated on relevant events)
	process (clk)
	begin
		if rising_edge(clk) then
			if sync = '1' then
				
				if LasersChanged = '1' then
					DoorSiteLaser <= DoorSiteLaser_I;
					RejectBinLaser <= RejectBinLaser_I;
					AcceptBinLaser <= AcceptBinLaser_I;
				end if;
				
			end if;
		end if;
	end process;
	
	--output var renaming, no output registers as inputs are stored where they are processed
	CanisterCount_O <= CanisterCount;
			
	
	-- Logic to advance to the next state
	process (clk, reset)
	begin
		if reset = '1' then
			state <= STATE_Start;
			AlgorithmsStart <= '1';
		elsif (rising_edge(clk)) then
			if AlgorithmsStart = '1' then --algorithms should be triggered only once via this pulse signal
				AlgorithmsStart <= '0';
			elsif enable = '1' then 
				--default values
				state <= state;
				AlgorithmsStart <= '0';

				--next state logic
				if AlgorithmsStart = '0' and AlgorithmsDone = '1' then
					case state is
						when STATE_Start =>
							if LasersChanged = '1' then
								state <= STATE_Start;
								AlgorithmsStart <= '1';
							end if;
						
					end case;
				end if;
			end if;
		end if;
	end process;

	-- Event outputs and internal algorithm triggers depend solely on the current state
	process (state)
	begin
		--default values
		--events
		CanisterCountChanged <= '0';
		
		--algorithms
		ChangeCount_alg_en <= '0'; 

		case state is
			when STATE_Start =>
				ChangeCount_alg_en <= '1';
				CanisterCountChanged <= '1';
				
			
		end case;
	end process;

	-- Algorithms process
	process(clk)
	begin
		if rising_edge(clk) then
			if AlgorithmsStart = '1' then			
				
				if ChangeCount_alg_en = '1' then -- Algorithm ChangeCount
					ChangeCount_alg_done <= '0';
				end if;
				
			end if;

			
			if ChangeCount_alg_done = '0' then -- Algorithm ChangeCount

--begin algorithm raw text
if DoorSiteLaser='1' then 
	CanisterCount <= CanisterCount + 1;
end if;
if RejectBinLaser = '1' or AcceptBinLaser = '1' then 
CanisterCount <= CanisterCount - 1;
end if;
ChangeCount_alg_done<='1';
--end algorithm raw text

			end if;
			
		end if;
	end process;

	--Done signal
	AlgorithmsDone <= (not AlgorithmsStart) and ChangeCount_alg_done;
	Done <= AlgorithmsDone;
end rtl;