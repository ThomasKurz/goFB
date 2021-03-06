
--This is an autogenerated file
--Do not modify it by hand
--Generated at 2017-12-08T14:22:41+13:00
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.enforcement_types_PaceEnforcer.all;

entity enforcer_PaceEnforcer_NO_AP_VP is
    port
    (
        clk         : in std_logic;
        reset       : in std_logic;
        t           : in unsigned(63 downto 0); --current time in nanoseconds
        e           : out std_logic;            --if enforcement occured

        --the input signals
        
        --the enforce signals
        q           : in enforced_signals_PaceEnforcer;
        q_prime     : out enforced_signals_PaceEnforcer
    );
end entity;

architecture behaviour of enforcer_PaceEnforcer_NO_AP_VP is
    
begin
    
    --trigger process
    process(reset, clk, q, t)
    variable q_enf: enforced_signals_PaceEnforcer;
    
    begin
        if(rising_edge(clk)) then
            --default values
            
            q_enf := q;
            e <= '0';

            --policies begin
            
            if(((q_enf.AP and q_enf.VP) = '0') ) then
                e <= '1';
                --recover
                q_enf.VP := '0';
                q_enf.AP := '0';
                
            end if;
            

            --Triggers begin (triggers are after policies because a policy might edit a value that a trigger depends on)
            
            
            q_prime <= q_enf;
        end if;
    end process;


end architecture;
